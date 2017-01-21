#include "cm_local.h"

#include <unordered_map>
#include <vector>

#define LL(x) x=LittleLong(x)

struct model_set {
	std::vector<char *> buffers;
	model_t * model;
};

std::unordered_map <qhandle_t, model_set> loaded_models;
std::unordered_map <std::string, qhandle_t> model_lookup;

static qhandle_t handle_incrementor = 1;
#define nexthand (handle_incrementor++)

static model_t bad_model {
	"",
	MOD_BAD,
};

static int OldToNewRemapTable[72] = {
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

static const byte FakeGLAFile[] =
{
0x32, 0x4C, 0x47, 0x41, 0x06, 0x00, 0x00, 0x00, 0x2A, 0x64, 0x65, 0x66, 0x61, 0x75, 0x6C, 0x74,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x01, 0x00, 0x00, 0x00,
0x14, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00,
0x26, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x4D, 0x6F, 0x64, 0x56, 0x69, 0x65, 0x77, 0x20,
0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x61, 0x6C, 0x20, 0x64, 0x65, 0x66, 0x61, 0x75, 0x6C, 0x74,
0x00, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,
0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,
0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD, 0xBF, 0xFE, 0x7F, 0xFE, 0x7F, 0xFE, 0x7F,
0x00, 0x80, 0x00, 0x80, 0x00, 0x80
};

qboolean LoadMDXA( model_t *mod, void *buffer, const char *mod_name, bool fakeGLA ) {

	mdxaHeader_t		*pinmodel, *mdxa;
	int					version;
	int					size;
#ifdef CREATE_LIMB_HIERARCHY
	int					oSize = 0;
	byte				*sizeMarker;
#endif
#ifdef Q3_BIG_ENDIAN
	int					j, k, i;
	mdxaSkel_t			*boneInfo;
	mdxaSkelOffsets_t	*offsets;
	int					maxBoneIndex = 0;
	mdxaCompQuatBone_t	*pCompBonePool;
	unsigned short		*pwIn;
	mdxaIndex_t			*pIndex;
#endif

 	pinmodel = (mdxaHeader_t *)buffer;
	//
	// read some fields from the binary, but only LittleLong() them when we know this wasn't an already-cached model...
	//
	version = (pinmodel->version);
	size	= (pinmodel->ofsEnd);

	if (!fakeGLA)
	{
		LL(version);
		LL(size);
	}

	if (version != MDXA_VERSION) {
		Com_Printf( S_COLOR_YELLOW  "R_LoadMDXA: %s has wrong version (%i should be %i)\n",
				 mod_name, version, MDXA_VERSION);
		return qfalse;
	}

	mod->type		= MOD_MDXA;
	mod->dataSize  += size;

	//qboolean bAlreadyFound = qfalse;

#ifdef CREATE_LIMB_HIERARCHY
	oSize = size;

	int childNumber = (NUM_ROOTPARENTS + NUM_OTHERPARENTS);
	size += (childNumber*(CHILD_PADDING*8)); //Allocate us some extra space so we can shift memory down.
#endif //CREATE_LIMB_HIERARCHY

	mdxa = mod->mdxa = (mdxaHeader_t*) buffer;

	//assert(bAlreadyCached == bAlreadyFound);	// I should probably eliminate 'bAlreadyFound', but wtf?

	if (!fakeGLA)
	{
#ifdef CREATE_LIMB_HIERARCHY
		memcpy( mdxa, buffer, oSize );
#else
		// horrible new hackery, if !bAlreadyFound then we've just done a tag-morph, so we need to set the
		//	bool reference passed into this function to true, to tell the caller NOT to do an ri->FS_Freefile since
		//	we've hijacked that memory block...
		//
		// Aaaargh. Kill me now...
		//
		//bAlreadyCached = qtrue;
		assert( mdxa == buffer );
//		memcpy( mdxa, buffer, size );	// and don't do this now, since it's the same thing
#endif
		LL(mdxa->ident);
		LL(mdxa->version);
		//LF(mdxa->fScale);
		LL(mdxa->numFrames);
		LL(mdxa->ofsFrames);
		LL(mdxa->numBones);
		LL(mdxa->ofsCompBonePool);
		LL(mdxa->ofsSkel);
		LL(mdxa->ofsEnd);
	}

#ifdef CREATE_LIMB_HIERARCHY
	if (!fakeGLA)
	{
		mdxaSkel_t			*boneParent;
#if 0 //#ifdef _M_IX86
		mdxaSkel_t			*boneInfo;
		int i, k;
#endif

		sizeMarker = (byte *)mdxa + mdxa->ofsEnd;

		//rww - This is probably temporary until we put actual hierarchy in for the models.
		//It is necessary for the correct operation of ragdoll.
   		mdxaSkelOffsets_t *offsets = (mdxaSkelOffsets_t *)((byte *)mdxa + sizeof(mdxaHeader_t));

		for ( i = 0 ; i < mdxa->numBones ; i++)
		{
			boneInfo = (mdxaSkel_t *)((byte *)mdxa + sizeof(mdxaHeader_t) + offsets->offsets[i]);

			if (boneInfo)
			{
				char *bname = boneInfo->name;

				if (BoneIsRootParent(bname))
				{ //These are the main parent bones. We don't want to change their parents, but we want to give them children.
					ShiftMemoryDown(offsets, mdxa, i, &sizeMarker);

					boneInfo = (mdxaSkel_t *)((byte *)mdxa + sizeof(mdxaHeader_t) + offsets->offsets[i]);

					int newChild = BoneParentChildIndex(mdxa, offsets, boneInfo, qtrue);

					if (newChild != -1)
					{
						boneInfo->numChildren++;
						boneInfo->children[boneInfo->numChildren-1] = newChild;
					}
					else
					{
						assert(!"Failed to find matching child for bone in hierarchy creation");
					}
				}
				else if (BoneIsOtherParent(bname) || BoneIsBottom(bname))
				{
					if (!BoneIsBottom(bname))
					{ //unless it's last in the chain it has the next bone as a child.
						ShiftMemoryDown(offsets, mdxa, i, &sizeMarker);

						boneInfo = (mdxaSkel_t *)((byte *)mdxa + sizeof(mdxaHeader_t) + offsets->offsets[i]);

						int newChild = BoneParentChildIndex(mdxa, offsets, boneInfo, qtrue);

						if (newChild != -1)
						{
							boneInfo->numChildren++;
							boneInfo->children[boneInfo->numChildren-1] = newChild;
						}
						else
						{
							assert(!"Failed to find matching child for bone in hierarchy creation");
						}
					}

					//Before we set the parent we want to remove this as a child for whoever was parenting it.
					int oldParent = boneInfo->parent;

					if (oldParent > -1)
					{
						boneParent = (mdxaSkel_t *)((byte *)mdxa + sizeof(mdxaHeader_t) + offsets->offsets[oldParent]);
					}
					else
					{
						boneParent = NULL;
					}

					if (boneParent)
					{
						k = 0;

						while (k < boneParent->numChildren)
						{
							if (boneParent->children[k] == i)
							{ //this bone is the child
								k++;
								while (k < boneParent->numChildren)
								{
									boneParent->children[k-1] = boneParent->children[k];
									k++;
								}
								boneParent->children[k-1] = 0;
								boneParent->numChildren--;
								break;
							}
							k++;
						}
					}

					//Now that we have cleared the original parent of ownership, mark the bone's new parent.
					int newParent = BoneParentChildIndex(mdxa, offsets, boneInfo, qfalse);

					if (newParent != -1)
					{
						boneInfo->parent = newParent;
					}
					else
					{
						assert(!"Failed to find matching parent for bone in hierarchy creation");
					}
				}
			}
		}
	}
#endif //CREATE_LIMB_HIERARCHY

 	if ( mdxa->numFrames < 1 ) {
		Com_Printf( S_COLOR_YELLOW  "R_LoadMDXA: %s has no frames\n", mod_name );
		return qfalse;
	}

	//if (bAlreadyFound)
	{
		return qtrue;	// All done, stop here, do not LittleLong() etc. Do not pass go...
	}

#ifdef Q3_BIG_ENDIAN
	// swap the bone info
	offsets = (mdxaSkelOffsets_t *)((byte *)mdxa + sizeof(mdxaHeader_t));
 	for ( i = 0; i < mdxa->numBones ; i++ )
 	{
		LL(offsets->offsets[i]);
 		boneInfo = (mdxaSkel_t *)((byte *)mdxa + sizeof(mdxaHeader_t) + offsets->offsets[i]);
		LL(boneInfo->flags);
		LL(boneInfo->parent);
		for ( j = 0; j < 3; j++ )
		{
			for ( k = 0; k < 4; k++)
			{
				LF(boneInfo->BasePoseMat.matrix[j][k]);
				LF(boneInfo->BasePoseMatInv.matrix[j][k]);
			}
		}
		LL(boneInfo->numChildren);

		for (k=0; k<boneInfo->numChildren; k++)
		{
			LL(boneInfo->children[k]);
		}
	}

	// find the largest index, since the actual number of compressed bone pools is not stored anywhere
	for ( i = 0 ; i < mdxa->numFrames ; i++ )
	{
		for ( j = 0 ; j < mdxa->numBones ; j++ )
		{
			k = (i * mdxa->numBones * 3) + (j * 3); // iOffsetToIndex
			pIndex = (mdxaIndex_t *) ((byte*) mdxa + mdxa->ofsFrames + k);

			// 3 byte ints, yeah...
			int tmp = pIndex->iIndex & 0xFFFFFF00;
			LL(tmp);

			if (maxBoneIndex < tmp)
				maxBoneIndex = tmp;
		}
	}

	// swap the compressed bones
	pCompBonePool = (mdxaCompQuatBone_t *) ((byte *)mdxa + mdxa->ofsCompBonePool);
	for ( i = 0 ; i <= maxBoneIndex ; i++ )
	{
		pwIn = (unsigned short *) pCompBonePool[i].Comp;

		for ( k = 0 ; k < 7 ; k++ )
			LS(pwIn[k]);
	}
#endif
	return qtrue;
}


static bool LoadMDXM( model_t *mod, void *buffer, const char *mod_name ) {
	int					i,l, j;
	mdxmHeader_t		*pinmodel, *mdxm;
	mdxmLOD_t			*lod;
	mdxmSurface_t		*surf;
	int					version;
	int					size;
	mdxmSurfHierarchy_t	*surfInfo;

#ifdef Q3_BIG_ENDIAN
	int					k;
	mdxmTriangle_t		*tri;
	mdxmVertex_t		*v;
	int					*boneRef;
	mdxmLODSurfOffset_t	*indexes;
	mdxmVertexTexCoord_t	*pTexCoords;
	mdxmHierarchyOffsets_t	*surfIndexes;
#endif

	pinmodel= (mdxmHeader_t *)buffer;
	//
	// read some fields from the binary, but only LittleLong() them when we know this wasn't an already-cached model...
	//
	version = (pinmodel->version);
	size	= (pinmodel->ofsEnd);

	LL(version);
	LL(size);

	if (version != MDXM_VERSION) {
		Com_Printf( S_COLOR_YELLOW  "R_LoadMDXM: %s has wrong version (%i should be %i)\n",
				 mod_name, version, MDXM_VERSION);
		return qfalse;
	}

	mod->type	   = MOD_MDXM;
	mod->dataSize += size;

//	qboolean bAlreadyFound = qfalse;
	mdxm = mod->mdxm = (mdxmHeader_t*) buffer;


//	if (!bAlreadyFound)
	{
		// horrible new hackery, if !bAlreadyFound then we've just done a tag-morph, so we need to set the
		//	bool reference passed into this function to true, to tell the caller NOT to do an ri->FS_Freefile since
		//	we've hijacked that memory block...
		//
		// Aaaargh. Kill me now...
		//
//		bAlreadyCached = qtrue;
		assert( mdxm == buffer );
//		memcpy( mdxm, buffer, size );	// and don't do this now, since it's the same thing

		LL(mdxm->ident);
		LL(mdxm->version);
		LL(mdxm->numBones);
		LL(mdxm->numLODs);
		LL(mdxm->ofsLODs);
		LL(mdxm->numSurfaces);
		LL(mdxm->ofsSurfHierarchy);
		LL(mdxm->ofsEnd);
	}

	// first up, go load in the animation file we need that has the skeletal animation info for this model
	mdxm->animIndex = CM_RegisterModel(va ("%s.gla",mdxm->animName));

	if (!mdxm->animIndex)
	{
		Com_Printf( S_COLOR_YELLOW  "R_LoadMDXM: missing animation file %s for mesh %s\n", mdxm->animName, mdxm->name);
		return qfalse;
	}

	mod->numLods = mdxm->numLODs -1 ;	//copy this up to the model for ease of use - it wil get inced after this.

//	if (bAlreadyFound)
	{
//		return qtrue;	// All done. Stop, go no further, do not LittleLong(), do not pass Go...
	}

	bool isAnOldModelFile = false;
	if (mdxm->numBones == 72 && strstr(mdxm->animName,"_humanoid") )
	{
		isAnOldModelFile = true;
	}

	surfInfo = (mdxmSurfHierarchy_t *)( (byte *)mdxm + mdxm->ofsSurfHierarchy);
#ifdef Q3_BIG_ENDIAN
	surfIndexes = (mdxmHierarchyOffsets_t *)((byte *)mdxm + sizeof(mdxmHeader_t));
#endif
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

#ifdef Q3_BIG_ENDIAN
		// swap the surface offset
		LL(surfIndexes->offsets[i]);
		assert(surfInfo == (mdxmSurfHierarchy_t *)((byte *)surfIndexes + surfIndexes->offsets[i]));
#endif

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
			surf->ident = 7; // FIXME HACK
			// register the shaders
#ifdef Q3_BIG_ENDIAN
			// swap the LOD offset
			indexes = (mdxmLODSurfOffset_t *)((byte *)lod + sizeof(mdxmLOD_t));
			LL(indexes->offsets[surf->thisSurfaceIndex]);

			// do all the bone reference data
			boneRef = (int *) ( (byte *)surf + surf->ofsBoneReferences );
			for ( j = 0 ; j < surf->numBoneReferences ; j++ )
			{
					LL(boneRef[j]);
			}

			// swap all the triangles
			tri = (mdxmTriangle_t *) ( (byte *)surf + surf->ofsTriangles );
			for ( j = 0 ; j < surf->numTriangles ; j++, tri++ )
			{
				LL(tri->indexes[0]);
				LL(tri->indexes[1]);
				LL(tri->indexes[2]);
			}

			// swap all the vertexes
			v = (mdxmVertex_t *) ( (byte *)surf + surf->ofsVerts );
			pTexCoords = (mdxmVertexTexCoord_t *) &v[surf->numVerts];

			for ( j = 0 ; j < surf->numVerts ; j++ )
			{
				LF(v->normal[0]);
				LF(v->normal[1]);
				LF(v->normal[2]);

				LF(v->vertCoords[0]);
				LF(v->vertCoords[1]);
				LF(v->vertCoords[2]);

				LF(pTexCoords[j].texCoords[0]);
				LF(pTexCoords[j].texCoords[1]);

				LL(v->uiNmWeightsAndBoneIndexes);

				v++;
			}
#endif

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

static bool LoadMD3 (model_t *mod, int lod, void *buffer, const char *mod_name ) {
	int					i, j;
	md3Header_t			*pinmodel;
	md3Surface_t		*surf;
	int					version;
	int					size;

#ifdef Q3_BIG_ENDIAN
	md3Frame_t			*frame;
	md3Triangle_t		*tri;
	md3St_t				*st;
	md3XyzNormal_t		*xyz;
	md3Tag_t			*tag;
#endif


	pinmodel= (md3Header_t *)buffer;
	//
	// read some fields from the binary, but only LittleLong() them when we know this wasn't an already-cached model...
	//
	version = pinmodel->version;
	size	= pinmodel->ofsEnd;

//	if (!bAlreadyCached)
	{
		LL(version);
		LL(size);
	}

	if (version != MD3_VERSION) {
		Com_Printf( S_COLOR_YELLOW  "R_LoadMD3: %s has wrong version (%i should be %i)\n",
				 mod_name, version, MD3_VERSION);
		return qfalse;
	}

	mod->type      = MOD_MESH;
	mod->dataSize += size;

//	qboolean bAlreadyFound = qfalse;
	mod->md3[lod] = (md3Header_t *) buffer;

//	assert(bAlreadyCached == bAlreadyFound);	// I should probably eliminate 'bAlreadyFound', but wtf?

//	if (!bAlreadyFound)
	{
		// horrible new hackery, if !bAlreadyFound then we've just done a tag-morph, so we need to set the
		//	bool reference passed into this function to true, to tell the caller NOT to do an ri->FS_Freefile since
		//	we've hijacked that memory block...
		//
		// Aaaargh. Kill me now...
		//
//		bAlreadyCached = qtrue;
		assert( mod->md3[lod] == buffer );
//		memcpy( mod->md3[lod], buffer, size );	// and don't do this now, since it's the same thing

		LL(mod->md3[lod]->ident);
		LL(mod->md3[lod]->version);
		LL(mod->md3[lod]->numFrames);
		LL(mod->md3[lod]->numTags);
		LL(mod->md3[lod]->numSurfaces);
		LL(mod->md3[lod]->ofsFrames);
		LL(mod->md3[lod]->ofsTags);
		LL(mod->md3[lod]->ofsSurfaces);
		LL(mod->md3[lod]->ofsEnd);
	}

	if ( mod->md3[lod]->numFrames < 1 ) {
		Com_Printf( S_COLOR_YELLOW  "R_LoadMD3: %s has no frames\n", mod_name );
		return qfalse;
	}

//	if (bAlreadyFound)
	{
//		return qtrue;	// All done. Stop, go no further, do not pass Go...
	}

#ifdef Q3_BIG_ENDIAN
	// swap all the frames
	frame = (md3Frame_t *) ( (byte *)mod->md3[lod] + mod->md3[lod]->ofsFrames );
	for ( i = 0 ; i < mod->md3[lod]->numFrames ; i++, frame++) {
		LF(frame->radius);
		for ( j = 0 ; j < 3 ; j++ ) {
			LF(frame->bounds[0][j]);
			LF(frame->bounds[1][j]);
			LF(frame->localOrigin[j]);
		}
	}

	// swap all the tags
	tag = (md3Tag_t *) ( (byte *)mod->md3[lod] + mod->md3[lod]->ofsTags );
	for ( i = 0 ; i < mod->md3[lod]->numTags * mod->md3[lod]->numFrames ; i++, tag++) {
		for ( j = 0 ; j < 3 ; j++ ) {
			LF(tag->origin[j]);
			LF(tag->axis[0][j]);
			LF(tag->axis[1][j]);
			LF(tag->axis[2][j]);
		}
	}
#endif

	// swap all the surfaces
	surf = (md3Surface_t *) ( (byte *)mod->md3[lod] + mod->md3[lod]->ofsSurfaces );
	for ( i = 0 ; i < mod->md3[lod]->numSurfaces ; i++) {
        LL(surf->flags);
        LL(surf->numFrames);
        LL(surf->numShaders);
        LL(surf->numTriangles);
        LL(surf->ofsTriangles);
        LL(surf->numVerts);
        LL(surf->ofsShaders);
        LL(surf->ofsSt);
        LL(surf->ofsXyzNormals);
        LL(surf->ofsEnd);

		if ( surf->numVerts >= SHADER_MAX_VERTEXES ) {
			Com_Error (ERR_DROP, "R_LoadMD3: %s has more than %i verts on %s (%i)",
				mod_name, SHADER_MAX_VERTEXES - 1, surf->name[0] ? surf->name : "a surface", surf->numVerts );
		}
		if ( surf->numTriangles*3 >= SHADER_MAX_INDEXES ) {
			Com_Error (ERR_DROP, "R_LoadMD3: %s has more than %i triangles on %s (%i)",
				mod_name, ( SHADER_MAX_INDEXES / 3 ) - 1, surf->name[0] ? surf->name : "a surface", surf->numTriangles );
		}

		// lowercase the surface name so skin compares are faster
		Q_strlwr( surf->name );

		// strip off a trailing _1 or _2
		// this is a crutch for q3data being a mess
		j = strlen( surf->name );
		if ( j > 2 && surf->name[j-2] == '_' ) {
			surf->name[j-2] = 0;
		}
		/*
        // register the shaders
		md3Shader_t		*shader;
        shader = (md3Shader_t *) ( (byte *)surf + surf->ofsShaders );
        for ( j = 0 ; j < surf->numShaders ; j++, shader++ ) {
            shader_t	*sh;

            sh = R_FindShader( shader->name, lightmapsNone, stylesDefault, qtrue );
			if ( sh->defaultShader ) {
				shader->shaderIndex = 0;
			} else {
				shader->shaderIndex = sh->index;
			}
			RE_RegisterModels_StoreShaderRequest(mod_name, &shader->name[0], &shader->shaderIndex);
        }
        */
#ifdef Q3_BIG_ENDIAN
		// swap all the triangles
		tri = (md3Triangle_t *) ( (byte *)surf + surf->ofsTriangles );
		for ( j = 0 ; j < surf->numTriangles ; j++, tri++ ) {
			LL(tri->indexes[0]);
			LL(tri->indexes[1]);
			LL(tri->indexes[2]);
		}

		// swap all the ST
		st = (md3St_t *) ( (byte *)surf + surf->ofsSt );
		for ( j = 0 ; j < surf->numVerts ; j++, st++ ) {
			LF(st->st[0]);
			LF(st->st[1]);
		}

		// swap all the XyzNormals
		xyz = (md3XyzNormal_t *) ( (byte *)surf + surf->ofsXyzNormals );
		for ( j = 0 ; j < surf->numVerts * surf->numFrames ; j++, xyz++ )
		{
			LS(xyz->xyz[0]);
			LS(xyz->xyz[1]);
			LS(xyz->xyz[2]);

			LS(xyz->normal);
		}
#endif

		// find the next surface
		surf = (md3Surface_t *)( (byte *)surf + surf->ofsEnd );
	}

	return qtrue;
}

/*
static float nullVerts[] = {
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f
};
static float nullUVs[] = {
	0.0f, 0.0f,
	0.0f, 0.0f,
	0.0f, 0.0f,
};
static float nullNormals[] = {
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f
};
*/

#define OBJ_MAX_INDICIES 1024
#define CMD_BUF_LEN 12
#define FLOAT_BUF_LEN 15

char const defaultShader[] = "textures/colors/c_grey";

bool LoadOBJ(model_t * model, char * obj_buf, long len, char const * name) {
	
	struct objWorkElement {
		int vert = 0;
		int uv = 0;
		int normal = 0;
	};
	
	struct objWorkFace {
		objWorkElement elements [3];
	};
	
	struct objWorkSurface {
		char shader[MAX_QPATH];
		int shaderIndex = 0;
		std::vector<objWorkFace> faces;
	};
	
	std::vector<float> verts;
	std::vector<float> uvs;
	std::vector<float> normals;
	std::vector<objWorkSurface> surfs;

	bool all_good = true;
	bool seekline = false;
	long obj_buf_i = 0;
	
	while (obj_buf_i < len && all_good) {
		
		switch (obj_buf[obj_buf_i]) {
		case '\r':
			obj_buf_i++;
			continue;
		case '\n':
			obj_buf_i++;
			seekline = false;
			continue;
		case '\0':
			all_good = false;
			continue;
		case '#':
			obj_buf_i++;
			seekline = true;
			continue;
		default:
			if (seekline) {
				obj_buf_i++;
				continue;
			}
			break;
		}
		
		char cmd_buf[CMD_BUF_LEN];
		int ci;
		for (ci = 0; ci < CMD_BUF_LEN; ci++) {
			switch(obj_buf[obj_buf_i+ci]) {
			case ' ':
				cmd_buf[ci] = '\0';
				break;
			default:
				cmd_buf[ci] = obj_buf[obj_buf_i+ci];
				continue;
			}
			break;
		}
		
		if (ci == CMD_BUF_LEN) {
			all_good = false;
			break;
		} else {
			obj_buf_i += ci + 1;
		}
		
		if (!strcmp(cmd_buf, "o")) {
			surfs.emplace_back();
			seekline = true;
			continue;
		} else if (!strcmp(cmd_buf, "v")) {
			char float_buf[FLOAT_BUF_LEN];
			for (int v = 0; v < 3; v++) {
				int vi;
				for(vi = 0; vi < FLOAT_BUF_LEN; vi++) {
					switch(obj_buf[obj_buf_i + vi]) {
					case '\r':
					case '\n':
					case ' ':
						float_buf[vi] = '\0';
						break;
					default:
						float_buf[vi] = obj_buf[obj_buf_i+vi];
						continue;
					}
					break;
				}
				obj_buf_i += vi + 1;
				float val = strtod(float_buf, nullptr);
				verts.push_back(val);
				memset(float_buf, FLOAT_BUF_LEN, sizeof(char));
			}
			obj_buf_i -= 2;
			seekline = true;
			continue;
		} else if (!strcmp(cmd_buf, "vn")) {
				char float_buf[FLOAT_BUF_LEN];
				for (int v = 0; v < 3; v++) {
					int vi;
					for(vi = 0; vi < FLOAT_BUF_LEN; vi++) {
						switch(obj_buf[obj_buf_i + vi]) {
						case '\r':
						case '\n':
						case ' ':
							float_buf[vi] = '\0';
							break;
						default:
							float_buf[vi] = obj_buf[obj_buf_i+vi];
							continue;
						}
						break;
					}
					obj_buf_i += vi + 1;
					float val = strtod(float_buf, nullptr);
					normals.push_back(val);
					memset(float_buf, FLOAT_BUF_LEN, sizeof(char));
				}
				obj_buf_i -= 2;
				seekline = true;
				continue;
		} else if (!strcmp(cmd_buf, "vt")) {
			char float_buf[FLOAT_BUF_LEN];
			for (int v = 0; v < 2; v++) {
				int vi;
				for(vi = 0; vi < FLOAT_BUF_LEN; vi++) {
					switch(obj_buf[obj_buf_i + vi]) {
					case '\r':
					case '\n':
					case ' ':
						float_buf[vi] = '\0';
						break;
					default:
						float_buf[vi] = obj_buf[obj_buf_i+vi];
						continue;
					}
					break;
				}
				obj_buf_i += vi + 1;
				float val = strtod(float_buf, nullptr);
				if (v) val = 1 - val;
				uvs.push_back(val);
				memset(float_buf, FLOAT_BUF_LEN, sizeof(char));
			}
			obj_buf_i -= 2;
			seekline = true;
			continue;
		} else if (!strcmp(cmd_buf, "f")) {
			objWorkSurface & cursurf = surfs.back();
			objWorkFace face;
			for (int fi = 0; fi < 3; fi++) {
				objWorkElement element;
				char int_buf[FLOAT_BUF_LEN];
				for (int v = 0; v < 3; v++) {
					int vi;
					for(vi = 0; vi < FLOAT_BUF_LEN; vi++) {
						switch(obj_buf[obj_buf_i + vi]) {
						case '\r':
						case '\n':
						case ' ':
							int_buf[vi] = '\0';
							v += 3;
							break;
						case '\\':
						case '/':
							int_buf[vi] = '\0';
							break;
						default:
							int_buf[vi] = obj_buf[obj_buf_i+vi];
							continue;
						}
						break;
					}
					obj_buf_i += vi + 1;
					int val = strtol(int_buf, nullptr, 10) - 1;
					switch(v) {
					case 0:
					case 3:
						element.vert = val;
					case 1:
					case 4:
						element.uv = val;
					case 2:
					case 5:
						element.normal = val;
					}
					memset(int_buf, FLOAT_BUF_LEN, sizeof(char));
				}
				face.elements[fi] = element;
			}
			cursurf.faces.push_back(face);
			obj_buf_i -= 2;
			seekline = true;
			continue;
		} else if (!strcmp(cmd_buf, "usemtl")) {
			objWorkSurface & cursurf = surfs.back();
			char nam_buf[MAX_QPATH];
			memset(nam_buf, '\0', MAX_QPATH);
			int ci = 0;
			while (true) {
				if (ci >= MAX_QPATH) Com_Error(ERR_DROP, "Obj model shader field exceeds MAX_QPATH(%i)", int(MAX_QPATH));
				switch(obj_buf[obj_buf_i]) {
				case '\r':
				case '\n':
				case ' ':
					nam_buf[ci++] = '\0';
					obj_buf_i++;
					break;
				case '\\':
					nam_buf[ci++] = '\0';
					obj_buf_i++;
					break;
				default:
					nam_buf[ci++] = obj_buf[obj_buf_i];
					obj_buf_i++;
					continue;
				}
				break;
			}

			strcpy(cursurf.shader, nam_buf);

			obj_buf_i -= 2;
			seekline = true;
			continue;
		} else {
			seekline = true;
			continue;
		}
	}
	
	if (all_good) {
	} else {
		Com_Printf("Obj Load Failed.\n");
		return false;
	}
	
	objModel_t * mod = new objModel_t;
	
	VectorSet(mod->mins, verts[0], verts[1], verts[2]);
	VectorSet(mod->maxs, verts[0], verts[1], verts[2]);
	
	for (size_t i = 3; i < verts.size(); i += 3) {
		if (verts[i] < mod->mins[0]) mod->mins[0] = verts[i];
		else if (verts[i] > mod->maxs[0]) mod->maxs[0] = verts[i];
		if (verts[i+1] < mod->mins[1]) mod->mins[1] = verts[i+1];
		else if (verts[i+1] > mod->maxs[1]) mod->maxs[1] = verts[i+1];
		if (verts[i+2] < mod->mins[2]) mod->mins[2] = verts[i+2];
		else if (verts[i+2] > mod->maxs[2]) mod->maxs[2] = verts[i+2];
	}
	
	mod->numVerts = verts.size();
	mod->verts = new float [mod->numVerts];
	memcpy(mod->verts, verts.data(), mod->numVerts * sizeof(float));
	
	mod->numUVs = uvs.size();
	mod->UVs = new float [mod->numUVs];
	memcpy(mod->UVs, uvs.data(), mod->numUVs * sizeof(float));
	
	mod->numNormals = normals.size();
	mod->normals = new float [mod->numNormals];
	memcpy(mod->normals, normals.data(), mod->numNormals * sizeof(float));
	
	mod->numVerts /= 3;
	mod->numUVs /= 2;
	mod->numNormals /= 3;
	
	mod->numSurfaces = surfs.size();
	mod->surfaces = new objSurface_t [mod->numSurfaces];
	for (int s = 0; s < mod->numSurfaces; s++) {
		
		objSurface_t & surfTo = mod->surfaces[s];
		objWorkSurface & surfFrom = surfs[s];
		
		if (strlen(surfFrom.shader)) strcpy(surfTo.shader, surfFrom.shader);
		else strcpy(surfTo.shader, defaultShader);
		surfTo.shaderIndex = surfFrom.shaderIndex;
		
		surfTo.numFaces = surfFrom.faces.size();
		surfTo.faces = new objFace_t [surfTo.numFaces];
		for (int f = 0; f < surfTo.numFaces; f++) {
			
			objFace_t & faceT = surfTo.faces[f];
			objWorkFace & faceF = surfFrom.faces[f];
			
			faceT[0].vertex = &mod->verts[faceF.elements[2].vert * 3];
			faceT[1].vertex = &mod->verts[faceF.elements[1].vert * 3];
			faceT[2].vertex = &mod->verts[faceF.elements[0].vert * 3];
			
			faceT[0].uv = &mod->UVs[faceF.elements[2].uv * 2];
			faceT[1].uv = &mod->UVs[faceF.elements[1].uv * 2];
			faceT[2].uv = &mod->UVs[faceF.elements[0].uv * 2];
			
			faceT[0].normal = &mod->normals[faceF.elements[2].normal * 3];
			faceT[1].normal = &mod->normals[faceF.elements[1].normal * 3];
			faceT[2].normal = &mod->normals[faceF.elements[0].normal * 3];
		}
	}
	
	model->obj = mod;
	model->type = MOD_OBJ;
	
	return true;
}

model_t * CM_GetModelByHandle(qhandle_t handle) {
	auto i = loaded_models.find(handle);
	if (i != loaded_models.end()) return i->second.model;
	
	return &bad_model;
}

qhandle_t CM_RegisterModel(char const * path) {
	auto i = model_lookup.find(path);
	if (i != model_lookup.end()) return i->second;
	
	if (path[0] == '*') {
		if (Q_stricmp(path, "*default.gla")) {
			return 0;
		}
	}
	
	int LoD_start, lod;
	
	LoD_start = 0;
	if (strstr (path, ".md3")) {
		LoD_start = MD3_MAX_LODS-1;
	}
	model_set mods;
	model_t * & mod = mods.model;
	mod = new model_t {};
	mod->numLods = 0;
	Q_strncpyz(mod->name, path, MAX_QPATH);
	
	int num_loaded = 0;
	for (lod = LoD_start; lod >= 0; lod --) {
		
		char filename [MAX_QPATH];
		strcpy( filename, path );
		
		if ( lod != 0 ) {
			char namebuf[80];

			if ( strrchr( filename, '.' ) ) {
				*strrchr( filename, '.' ) = 0;
			}
			sprintf( namebuf, "_%d.md3", lod );
			strcat( filename, namebuf );
		}
		
		char * buf = nullptr;
		long buf_len = 0;
		bool fakeGLA = false;
		if (!strcmp(filename, "*default.gla")) {
			buf = new char [sizeof(FakeGLAFile)];
			memcpy(buf, FakeGLAFile, sizeof(FakeGLAFile));
			fakeGLA = true;
		} else {
			fileHandle_t f;
			buf_len = FS_FOpenFileRead(filename, &f, qfalse);
			if (buf_len <= 0) continue;
			
			buf = new char [buf_len];
			FS_Read(buf, buf_len, f);
			FS_FCloseFile(f);
			mods.buffers.push_back(buf);
		}
		
		bool loaded = false;
		
		if (strlen(path) > 4 && !strcmp(".obj", path + strlen(path) - 4)) {
			loaded = LoadOBJ( mod, buf, buf_len, path );
			if (!loaded) goto fail;
			num_loaded++;
			continue;
		}
		
		unsigned int ident = *reinterpret_cast<unsigned int *>(buf);
		LL(ident);
		
		switch (ident) {
			default:
				goto fail;
			case MDXA_IDENT:
				loaded = LoadMDXA(mod, buf, path, fakeGLA);
				break;
			case MDXM_IDENT:
				loaded = LoadMDXM(mod, buf, path);
				break;
			case MD3_IDENT:
				loaded = LoadMD3(mod, lod, buf, path);
				break;
		}
		
		if (!loaded) {
			if (lod == 0) goto fail;
			break;
		} else {
			mod->numLods++;
			num_loaded++;
		}
	}
	
	if (num_loaded) {
		for ( lod-- ; lod >= 0 ; lod-- ) {
			mod->numLods++;
			mod->md3[lod] = mod->md3[lod+1];
		}
		qhandle_t nh = nexthand;
		model_lookup[path] = nh;
		loaded_models[nh] = mods;
		mod->index = nh;
		return nh;
	} else {
		fail:
		delete mod;
		for (char * buf : mods.buffers) delete [] buf;
		model_lookup[path] = 0;
		return 0;
	}
}

model_t * CM_RegisterModelDirect(char const * path) {
	qhandle_t h = CM_RegisterModel(path);
	if (!h) return &bad_model;
	return CM_GetModelByHandle(h);
}

void CM_LoadBSPSubmodels() {

}

void CM_ClearModels() {
	return;
	for (auto const & ms : loaded_models) {
		delete ms.second.model; // TODO need to delete data inside models
		for (char * buf : ms.second.buffers) {
			delete [] buf;
		}
	}
	loaded_models.clear();
	model_lookup.clear();
	handle_incrementor = 1;
}
