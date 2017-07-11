#include "rendm_local.h"

#include <unordered_map>
#include <vector>

GLuint rendm::model::fullquad = 0;
GLuint rendm::model::unitquad = 0;

static GLfloat fullscreen_quad_verts [] = {
	-1, -1,  0,
	-1,  1,  0,
	 1, -1,  0,
	 1,  1,  0,
};

static GLfloat unit_quad_verts [] = {
	 0,  0,  0,
	 0,  1,  0,
	 1,  0,  0,
	 1,  1,  0,
};

static GLfloat quad_uvs [] = {
	 0,  0,
	 0,  1,
	 1,  0,
	 1,  1,
};

static qhandle_t handle_incrementor = 0;
#define nexthand (handle_incrementor++)

static std::unordered_map<std::string, qhandle_t> rendm_lookup;
static std::unordered_map<qhandle_t, rendm::model::model_set> rendm_models;
static std::unordered_map<GLuint, std::vector<GLuint>> vbo_map;

static void setup_fullquad() {
	
	GLuint vao;
	model_t * fqm;
	qhandle_t handle = nexthand;
	
	fqm = new model_t {};
	fqm->type = MOD_MESH;
	strcpy(fqm->name, "Fullscreen Quad");
	fqm->index = handle;
	
	glCreateVertexArrays(1, &vao);
	std::vector<GLuint> & vbos = vbo_map[vao];
	vbos.resize(2);
	glCreateBuffers(2, vbos.data());
	
	rendm::model::fullquad = vao;
	
	GLuint vbo_v = vbos[0];
	glNamedBufferData(vbo_v, sizeof(fullscreen_quad_verts), fullscreen_quad_verts, GL_STATIC_DRAW);
	glVertexArrayAttribBinding(vao, 0, 0);
	glVertexArrayVertexBuffer(vao, 0, vbo_v, 0, 12);
	glEnableVertexArrayAttrib(vao, 0);
	glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
	
	GLuint vbo_u = vbos[1];
	glNamedBufferData(vbo_u, sizeof(quad_uvs), quad_uvs, GL_STATIC_DRAW);
	glVertexArrayAttribBinding(vao, 1, 1);
	glVertexArrayVertexBuffer(vao, 1, vbo_u, 0, 8);
	glEnableVertexArrayAttrib(vao, 1);
	glVertexArrayAttribFormat(vao, 1, 2, GL_FLOAT, GL_FALSE, 0);
}

static void setup_unitquad() {
	
	GLuint vao;
	model_t * uqm;
	qhandle_t handle = nexthand;
	
	uqm = new model_t {};
	uqm->type = MOD_MESH;
	strcpy(uqm->name, "Unit Quad");
	uqm->index = handle;
	
	glCreateVertexArrays(1, &vao);
	std::vector<GLuint> & vbos = vbo_map[vao];
	vbos.resize(2);
	glCreateBuffers(2, vbos.data());
	
	rendm::model::unitquad = vao;
	
	GLuint vbo_v = vbos[0];
	glNamedBufferData(vbo_v, sizeof(unit_quad_verts), unit_quad_verts, GL_STATIC_DRAW);
	glVertexArrayAttribBinding(vao, 0, 0);
	glVertexArrayVertexBuffer(vao, 0, vbo_v, 0, 12);
	glEnableVertexArrayAttrib(vao, 0);
	glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
	
	GLuint vbo_u = vbos[1];
	glNamedBufferData(vbo_u, sizeof(quad_uvs), quad_uvs, GL_STATIC_DRAW);
	glVertexArrayAttribBinding(vao, 1, 1);
	glVertexArrayVertexBuffer(vao, 1, vbo_u, 0, 8);
	glEnableVertexArrayAttrib(vao, 1);
	glVertexArrayAttribFormat(vao, 1, 2, GL_FLOAT, GL_FALSE, 0);
}

static void add_basic_meshes() {
	setup_fullquad();
	setup_unitquad();
}

bool rendm::model::init() {
	add_basic_meshes();
	return true;
}

void rendm::model::term() {
	for (auto & i : vbo_map) {
		glDeleteVertexArrays(1, &i.first);
		glDeleteBuffers(i.second.size(), i.second.data());
	}
	for (auto & i : rendm_models) {
		delete i.second.model;
	}
	vbo_map.clear();
	rendm_models.clear();
	handle_incrementor = 0;
}

typedef enum {
	SF_BAD,
	SF_SKIP,				// ignore
	SF_FACE,
	SF_GRID,
	SF_TRIANGLES,
	SF_POLY,
	SF_MD3,
/*
Ghoul2 Insert Start
*/
	SF_MDX,
/*
Ghoul2 Insert End
*/
	SF_FLARE,
	SF_ENTITY,				// beams, rails, lightning, etc that can be determined by entity
	SF_DISPLAY_LIST,

	SF_NUM_SURFACE_TYPES,
	SF_MAX = 0xffffffff			// ensures that sizeof( surfaceType_t ) == sizeof( int )
} surfaceType_t;

int OldToNewRemapTable[72] = {
0,// Bone 0:   "model_root":           Parent: ""  (index -1)
1,// Bone 1:   "pelvis":               Parent: "model_root"  (index 0)
2,// Bone 2:   "Motion":               Parent: "pelvis"  (index 1)
3,// Bone 3:   "lfemurYZ":             Parent: "pelvis"  (index 1)
4,// Bone 4:   "lfemurX":              Parent: "pelvis"  (index 1)
5,// Bone 5:   "ltibia":               Parent: "pelvis"  (index 1)
6,// Bone 6:   "ltalus":               Parent: "pelvis"  (index 1)
6,// Bone 7:   "ltarsal":              Parent: "pelvis"  (index 1)
7,// Bone 8:   "rfemurYZ":             Parent: "pelvis"  (index 1)
8,// Bone 9:   "rfemurX":	            Parent: "pelvis"  (index 1)
9,// Bone10:   "rtibia":	            Parent: "pelvis"  (index 1)
10,// Bone11:   "rtalus":	            Parent: "pelvis"  (index 1)
10,// Bone12:   "rtarsal":              Parent: "pelvis"  (index 1)
11,// Bone13:   "lower_lumbar":         Parent: "pelvis"  (index 1)
12,// Bone14:   "upper_lumbar":	        Parent: "lower_lumbar"  (index 13)
13,// Bone15:   "thoracic":	            Parent: "upper_lumbar"  (index 14)
14,// Bone16:   "cervical":	            Parent: "thoracic"  (index 15)
15,// Bone17:   "cranium":              Parent: "cervical"  (index 16)
16,// Bone18:   "ceyebrow":	            Parent: "face_always_"  (index 71)
17,// Bone19:   "jaw":                  Parent: "face_always_"  (index 71)
18,// Bone20:   "lblip2":	            Parent: "face_always_"  (index 71)
19,// Bone21:   "leye":		            Parent: "face_always_"  (index 71)
20,// Bone22:   "rblip2":	            Parent: "face_always_"  (index 71)
21,// Bone23:   "ltlip2":               Parent: "face_always_"  (index 71)
22,// Bone24:   "rtlip2":	            Parent: "face_always_"  (index 71)
23,// Bone25:   "reye":		            Parent: "face_always_"  (index 71)
24,// Bone26:   "rclavical":            Parent: "thoracic"  (index 15)
25,// Bone27:   "rhumerus":             Parent: "thoracic"  (index 15)
26,// Bone28:   "rhumerusX":            Parent: "thoracic"  (index 15)
27,// Bone29:   "rradius":              Parent: "thoracic"  (index 15)
28,// Bone30:   "rradiusX":             Parent: "thoracic"  (index 15)
29,// Bone31:   "rhand":                Parent: "thoracic"  (index 15)
29,// Bone32:   "mc7":                  Parent: "thoracic"  (index 15)
34,// Bone33:   "r_d5_j1":              Parent: "thoracic"  (index 15)
35,// Bone34:   "r_d5_j2":              Parent: "thoracic"  (index 15)
35,// Bone35:   "r_d5_j3":              Parent: "thoracic"  (index 15)
30,// Bone36:   "r_d1_j1":              Parent: "thoracic"  (index 15)
31,// Bone37:   "r_d1_j2":              Parent: "thoracic"  (index 15)
31,// Bone38:   "r_d1_j3":              Parent: "thoracic"  (index 15)
32,// Bone39:   "r_d2_j1":              Parent: "thoracic"  (index 15)
33,// Bone40:   "r_d2_j2":              Parent: "thoracic"  (index 15)
33,// Bone41:   "r_d2_j3":              Parent: "thoracic"  (index 15)
32,// Bone42:   "r_d3_j1":			    Parent: "thoracic"  (index 15)
33,// Bone43:   "r_d3_j2":		        Parent: "thoracic"  (index 15)
33,// Bone44:   "r_d3_j3":              Parent: "thoracic"  (index 15)
34,// Bone45:   "r_d4_j1":              Parent: "thoracic"  (index 15)
35,// Bone46:   "r_d4_j2":	            Parent: "thoracic"  (index 15)
35,// Bone47:   "r_d4_j3":		        Parent: "thoracic"  (index 15)
36,// Bone48:   "rhang_tag_bone":	    Parent: "thoracic"  (index 15)
37,// Bone49:   "lclavical":            Parent: "thoracic"  (index 15)
38,// Bone50:   "lhumerus":	            Parent: "thoracic"  (index 15)
39,// Bone51:   "lhumerusX":	        Parent: "thoracic"  (index 15)
40,// Bone52:   "lradius":	            Parent: "thoracic"  (index 15)
41,// Bone53:   "lradiusX":	            Parent: "thoracic"  (index 15)
42,// Bone54:   "lhand":	            Parent: "thoracic"  (index 15)
42,// Bone55:   "mc5":		            Parent: "thoracic"  (index 15)
43,// Bone56:   "l_d5_j1":	            Parent: "thoracic"  (index 15)
44,// Bone57:   "l_d5_j2":	            Parent: "thoracic"  (index 15)
44,// Bone58:   "l_d5_j3":	            Parent: "thoracic"  (index 15)
43,// Bone59:   "l_d4_j1":	            Parent: "thoracic"  (index 15)
44,// Bone60:   "l_d4_j2":	            Parent: "thoracic"  (index 15)
44,// Bone61:   "l_d4_j3":	            Parent: "thoracic"  (index 15)
45,// Bone62:   "l_d3_j1":	            Parent: "thoracic"  (index 15)
46,// Bone63:   "l_d3_j2":	            Parent: "thoracic"  (index 15)
46,// Bone64:   "l_d3_j3":	            Parent: "thoracic"  (index 15)
45,// Bone65:   "l_d2_j1":	            Parent: "thoracic"  (index 15)
46,// Bone66:   "l_d2_j2":	            Parent: "thoracic"  (index 15)
46,// Bone67:   "l_d2_j3":	            Parent: "thoracic"  (index 15)
47,// Bone68:   "l_d1_j1":				Parent: "thoracic"  (index 15)
48,// Bone69:   "l_d1_j2":	            Parent: "thoracic"  (index 15)
48,// Bone70:   "l_d1_j3":				Parent: "thoracic"  (index 15)
52// Bone71:   "face_always_":			Parent: "cranium"  (index 17)
};

static qboolean R_LoadMDXM( model_t *mod, void *buffer, const char *mod_name ) {
	int					i,l, j;
	mdxmHeader_t		*pinmodel, *mdxm;
	mdxmLOD_t			*lod;
	mdxmSurface_t		*surf;
	int					version;
	int					size;
	mdxmSurfHierarchy_t	*surfInfo;

	pinmodel= (mdxmHeader_t *)buffer;
	//
	// read some fields from the binary, but only LittleLong() them when we know this wasn't an already-cached model...
	//
	version = (pinmodel->version);
	size	= (pinmodel->ofsEnd);

	if (version != MDXM_VERSION) {
		ri->Printf( PRINT_ALL, S_COLOR_YELLOW  "R_LoadMDXM: %s has wrong version (%i should be %i)\n",
				 mod_name, version, MDXM_VERSION);
		return qfalse;
	}

	mod->type	   = MOD_MDXM;
	mod->dataSize += size;

	mdxm = mod->mdxm = (mdxmHeader_t*) pinmodel;

	// first up, go load in the animation file we need that has the skeletal animation info for this model
	mdxm->animIndex = rendm::model::reg(va ("%s.gla",mdxm->animName));

	if (!mdxm->animIndex)
	{
		ri->Printf( PRINT_ALL, S_COLOR_YELLOW  "R_LoadMDXM: missing animation file %s for mesh %s\n", mdxm->animName, mdxm->name);
		return qfalse;
	}

	mod->numLods = mdxm->numLODs -1 ;	//copy this up to the model for ease of use - it wil get inced after this.

	bool isAnOldModelFile = false;
	if (mdxm->numBones == 72 && strstr(mdxm->animName,"_humanoid") )
	{
		isAnOldModelFile = true;
	}

	surfInfo = (mdxmSurfHierarchy_t *)( (byte *)mdxm + mdxm->ofsSurfHierarchy);
 	for ( i = 0 ; i < mdxm->numSurfaces ; i++)
	{
		LL(surfInfo->flags);
		LL(surfInfo->numChildren);
		LL(surfInfo->parentIndex);

		Q_strlwr(surfInfo->name);	//just in case
		if ( !strcmp( &surfInfo->name[strlen(surfInfo->name)-4],"_off") )
		{
			surfInfo->name[strlen(surfInfo->name)-4]=0;	//remove "_off" from name
		}

		// do all the children indexs
		for (j=0; j<surfInfo->numChildren; j++)
		{
			LL(surfInfo->childIndexes[j]);
		}

		surfInfo->shaderIndex = 0; // FIXME -- actual shader lookup (see below commented section)
		/*
		shader_t	*sh;
		// get the shader name
		sh = R_FindShader( surfInfo->shader, lightmapsNone, stylesDefault, qtrue );
		// insert it in the surface list
		if ( sh->defaultShader )
		{
			surfInfo->shaderIndex = 0;
		}
		else
		{
			surfInfo->shaderIndex = sh->index;
		}

		RE_RegisterModels_StoreShaderRequest(mod_name, &surfInfo->shader[0], &surfInfo->shaderIndex);
		*/

		// find the next surface
		surfInfo = (mdxmSurfHierarchy_t *)( (byte *)surfInfo + (size_t)( &((mdxmSurfHierarchy_t *)0)->childIndexes[ surfInfo->numChildren ] ));
  	}

	// swap all the LOD's	(we need to do the middle part of this even for intel, because of shader reg and err-check)
	lod = (mdxmLOD_t *) ( (byte *)mdxm + mdxm->ofsLODs );
	for ( l = 0 ; l < mdxm->numLODs ; l++)
	{
		int	triCount = 0;

		LL(lod->ofsEnd);
		// swap all the surfaces
		surf = (mdxmSurface_t *) ( (byte *)lod + sizeof (mdxmLOD_t) + (mdxm->numSurfaces * sizeof(mdxmLODSurfOffset_t)) );
		for ( i = 0 ; i < mdxm->numSurfaces ; i++)
		{
			LL(surf->thisSurfaceIndex);
			LL(surf->ofsHeader);
			LL(surf->numVerts);
			LL(surf->ofsVerts);
			LL(surf->numTriangles);
			LL(surf->ofsTriangles);
			LL(surf->numBoneReferences);
			LL(surf->ofsBoneReferences);
			LL(surf->ofsEnd);

			triCount += surf->numTriangles;

			if ( surf->numVerts > SHADER_MAX_VERTEXES ) {
				Com_Error (ERR_DROP, "R_LoadMDXM: %s has more than %i verts on a surface (%i)",
					mod_name, SHADER_MAX_VERTEXES, surf->numVerts );
			}
			if ( surf->numTriangles*3 > SHADER_MAX_INDEXES ) {
				Com_Error (ERR_DROP, "R_LoadMDXM: %s has more than %i triangles on a surface (%i)",
					mod_name, SHADER_MAX_INDEXES / 3, surf->numTriangles );
			}

			// change to surface identifier
			surf->ident = SF_MDX;

			if (isAnOldModelFile)
			{
				int *boneRef = (int *) ( (byte *)surf + surf->ofsBoneReferences );
				for ( j = 0 ; j < surf->numBoneReferences ; j++ )
				{
					assert(boneRef[j] >= 0 && boneRef[j] < 72);
					if (boneRef[j] >= 0 && boneRef[j] < 72)
					{
						boneRef[j]=OldToNewRemapTable[boneRef[j]];
					}
					else
					{
						boneRef[j]=0;
					}
				}
			}
			// find the next surface
			surf = (mdxmSurface_t *)( (byte *)surf + surf->ofsEnd );
		}
		// find the next LOD
		lod = (mdxmLOD_t *)( (byte *)lod + lod->ofsEnd );
	}
	return qtrue;
}

qboolean R_LoadMDXA( model_t *mod, void *buffer, const char *mod_name ) {

	mdxaHeader_t		*pinmodel, *mdxa;
	int					version;
	int					size;
	
 	pinmodel = (mdxaHeader_t *)buffer;
	//
	// read some fields from the binary, but only LittleLong() them when we know this wasn't an already-cached model...
	//
	version = (pinmodel->version);
	size	= (pinmodel->ofsEnd);

	if (version != MDXA_VERSION) {
		ri->Printf( PRINT_ALL, S_COLOR_YELLOW  "R_LoadMDXA: %s has wrong version (%i should be %i)\n",
				 mod_name, version, MDXA_VERSION);
		return qfalse;
	}

	mod->type = MOD_MDXA;
	mod->dataSize  += size;

	mdxa = mod->mdxa = pinmodel;

 	if ( mdxa->numFrames < 1 ) {
		ri->Printf( PRINT_ALL, S_COLOR_YELLOW  "R_LoadMDXA: %s has no frames\n", mod_name );
		return qfalse;
	}
	
	return qtrue;
}

qhandle_t rendm::model::reg(char const * path) {
	
	auto i = rendm_lookup.find(path);
	if (i != rendm_lookup.end()) return i->second;
	
	fileHandle_t f;
	char * buf;
	
	long len = ri->FS_FOpenFileRead(path, &f, qfalse);
	if (len <= 0) return 0;
	buf = new char [len];
	ri->FS_Read(buf, len, f);
	ri->FS_FCloseFile(f);
	int ident = *reinterpret_cast<int *>(buf);
	
	qhandle_t h = nexthand;
	
	model_t * mod = new model_t {};
	strcpy(mod->name, path);
	mod->index = h;
	mod->dataSize = len;
	
	switch (ident) {
		case MDXA_IDENT:
			Com_Printf("Ghoul2 Animation: %s\n", path);
			R_LoadMDXA(mod, buf, path);
			break;
		case MDXM_IDENT:
			Com_Printf("Ghoul2 Model: %s\n", path);
			R_LoadMDXM(mod, buf, path);
			break;
		case MD3_IDENT:
			Com_Printf("MD3 Model: %s\n", path);
			mod->type = MOD_MESH;
			break;
	}
	
	//delete [] buf;
	rendm_models[h] = {0, mod};
	rendm_lookup[path] = h;
	return h;
}

model_t * rendm::model::get(qhandle_t h) {
	auto i = rendm_models.find(h);
	if (i == rendm_models.end()) return nullptr;
	return i->second.model;
}
