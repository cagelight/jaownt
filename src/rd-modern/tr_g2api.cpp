#include "tr_local.h"
#include "rendm_local.h"

#include "ghoul2/g2_local.h"

/* GHOUL2 REWRITE (this is impossible) */

#define TOIMPLEMENT printf("IMPLEMENT THIS FUNCTION: %s\n", __PRETTY_FUNCTION__);

void G2API_SetTime(int currentTime, int clock) {
	//TOIMPLEMENT
}

int G2API_GetTime(int argTime) {
	//TOIMPLEMENT
	return 0;
}

qhandle_t G2API_PrecacheGhoul2Model(char const * fileName) {
	TOIMPLEMENT
	return 0;
}

qboolean G2API_IsGhoul2InfovValid (CGhoul2Info_v& ghoul2) {
	TOIMPLEMENT
	return qfalse;
}

int G2API_InitGhoul2Model(CGhoul2Info_v * * ghoul2Ptr, char const * fileName, int modelIndex, qhandle_t customSkin, qhandle_t customShader, int modelFlags, int lodBias) {
	
	auto mh = rendm::model::reg(fileName);
	return mh;
}

qboolean G2API_SetLodBias(CGhoul2Info * ghlInfo, int lodBias) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetSkin(CGhoul2Info_v& ghoul2, int modelIndex, qhandle_t customSkin, qhandle_t renderSkin) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetShader(CGhoul2Info * ghlInfo, qhandle_t customShader) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_HasGhoul2ModelOnIndex(CGhoul2Info_v * * ghlRemove, const int modelIndex) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RemoveGhoul2Model(CGhoul2Info_v * * ghlRemove, const int modelIndex) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RemoveGhoul2Models(CGhoul2Info_v * * ghlRemove) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetSurfaceOnOff(CGhoul2Info_v &ghoul2, char const * surfaceName, const int flags) {
	TOIMPLEMENT
	return qfalse;
}

int G2API_GetSurfaceOnOff(CGhoul2Info * ghlInfo, char const * surfaceName) {
	TOIMPLEMENT
	return 0;
}

qboolean G2API_SetRootSurface(CGhoul2Info_v &ghoul2, const int modelIndex, char const * surfaceName) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RemoveSurface(CGhoul2Info * ghlInfo, const int index) {
	TOIMPLEMENT
	return qfalse;
}

int G2API_AddSurface(CGhoul2Info * ghlInfo, int surfaceNumber, int polyNumber, float BarycentricI, float BarycentricJ, int lod ) {
	TOIMPLEMENT
	return 0;
}

qboolean G2API_SetBoneAnim(CGhoul2Info_v &ghoul2, const int modelIndex, char const * boneName, const int startFrame, const int endFrame, const int flags, const float animSpeed, const int currentTime, const float setFrame, const int blendTime) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_GetBoneAnim(CGhoul2Info_v& ghoul2, int modelIndex, char const * boneName, const int currentTime, float * currentFrame, int * startFrame, int * endFrame, int * flags, float * animSpeed, qhandle_t * modelList) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_GetAnimRange(CGhoul2Info * ghlInfo, char const * boneName, int * startFrame, int * endFrame) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_PauseBoneAnim(CGhoul2Info * ghlInfo, char const * boneName, const int currentTime) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_IsPaused(CGhoul2Info * ghlInfo, char const * boneName) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_StopBoneAnim(CGhoul2Info * ghlInfo, char const * boneName) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetBoneAngles(CGhoul2Info_v &ghoul2, const int modelIndex, char const * boneName, const vec3_t angles, const int flags, const Eorientations up, const Eorientations left, const Eorientations forward, qhandle_t * modelList, int blendTime, int currentTime ) {
	TOIMPLEMENT
	return qfalse;
}


qboolean G2API_StopBoneAngles(CGhoul2Info * ghlInfo, char const * boneName) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RemoveBone(CGhoul2Info_v& ghoul2, int modelIndex, char const * boneName) {
	TOIMPLEMENT
	return qfalse;
}

void G2API_AnimateG2Models(CGhoul2Info_v &ghoul2, float speedVar) {
	TOIMPLEMENT
}

qboolean G2API_RemoveBolt(CGhoul2Info * ghlInfo, const int index) {
	TOIMPLEMENT
	return qfalse;
}

int G2API_AddBolt(CGhoul2Info_v &ghoul2, const int modelIndex, char const * boneName) {
	TOIMPLEMENT
	return 0;
}

int G2API_AddBoltSurfNum(CGhoul2Info * ghlInfo, const int surfIndex) {
	TOIMPLEMENT
	return 0;
}

void G2API_SetBoltInfo(CGhoul2Info_v &ghoul2, int modelIndex, int boltInfo) {
	TOIMPLEMENT
}

qboolean G2API_AttachG2Model(CGhoul2Info_v &ghoul2From, int modelFrom, CGhoul2Info_v &ghoul2To, int toBoltIndex, int toModel) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_DetachG2Model(CGhoul2Info * ghlInfo) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_AttachEnt(int * boltInfo, CGhoul2Info_v& ghoul2, int modelIndex, int toBoltIndex, int entNum, int toModelNum) {
	TOIMPLEMENT
	return qfalse;
}

void G2API_DetachEnt(int * boltInfo) {
	TOIMPLEMENT
}


qboolean G2API_GetBoltMatrix(CGhoul2Info_v &ghoul2, const int modelIndex, const int boltIndex, mdxaBone_t * matrix, const vec3_t angles, const vec3_t position, const int frameNum, qhandle_t * modelList, vec3_t scale) {
	TOIMPLEMENT
	return qfalse;
}


void G2API_ListSurfaces(CGhoul2Info * ghlInfo) {
	TOIMPLEMENT
}

void G2API_ListBones(CGhoul2Info * ghlInfo, int frame) {
	TOIMPLEMENT
}

qboolean G2API_HaveWeGhoul2Models(CGhoul2Info_v &ghoul2) {
	TOIMPLEMENT
	return qfalse;
}

void G2API_SetGhoul2ModelIndexes(CGhoul2Info_v &ghoul2, qhandle_t * modelList, qhandle_t * skinList) {
	TOIMPLEMENT
}

qboolean G2API_SetGhoul2ModelFlags(CGhoul2Info * ghlInfo, const int flags) {
	TOIMPLEMENT
	return qfalse;
}

int G2API_GetGhoul2ModelFlags(CGhoul2Info * ghlInfo) {
	TOIMPLEMENT
	return 0;
}


qboolean G2API_GetAnimFileName(CGhoul2Info * ghlInfo, char * * filename) {
	TOIMPLEMENT
	return qfalse;
}

void G2API_CollisionDetect(CollisionRecord_t * collRecMap, CGhoul2Info_v &ghoul2, const vec3_t angles, const vec3_t position, int frameNumber, int entNum, vec3_t rayStart, vec3_t rayEnd, vec3_t scale, IHeapAllocator * G2VertSpace, int traceFlags, int useLod, float fRadius) {
	TOIMPLEMENT
}

void G2API_CollisionDetectCache(CollisionRecord_t * collRecMap, CGhoul2Info_v &ghoul2, const vec3_t angles, const vec3_t position, int frameNumber, int entNum, vec3_t rayStart, vec3_t rayEnd, vec3_t scale, IHeapAllocator * G2VertSpace, int traceFlags, int useLod, float fRadius) {
	TOIMPLEMENT
}


void G2API_GiveMeVectorFromMatrix(mdxaBone_t * boltMatrix, Eorientations flags, vec3_t vec) {
	TOIMPLEMENT
}

int G2API_CopyGhoul2Instance(CGhoul2Info_v &g2From, CGhoul2Info_v &g2To, int modelIndex) {
	TOIMPLEMENT
	return 0;
}

void G2API_CleanGhoul2Models(CGhoul2Info_v * * ghoul2Ptr) {
	TOIMPLEMENT
}

int G2API_GetParentSurface(CGhoul2Info * ghlInfo, const int index) {
	TOIMPLEMENT
	return 0;
}

int G2API_GetSurfaceIndex(CGhoul2Info * ghlInfo, char const * surfaceName) {
	TOIMPLEMENT
	return 0;
}

char * G2API_GetSurfaceName(CGhoul2Info_v& ghoul2, int modelIndex, int surfNumber) {
	TOIMPLEMENT
	return va("%s", "not implemented");
}

char * G2API_GetGLAName(CGhoul2Info_v &ghoul2, int modelIndex) {
	TOIMPLEMENT
	return va("%s", "not implemented");
}

qboolean G2API_SetBoneAnglesMatrix(CGhoul2Info * ghlInfo, char const * boneName, const mdxaBone_t &matrix, const int flags, qhandle_t * modelList, int blendTime, int currentTime) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetNewOrigin(CGhoul2Info_v &ghoul2, const int boltIndex) {
	TOIMPLEMENT
	return qfalse;
}

int G2API_GetBoneIndex(CGhoul2Info * ghlInfo, char const * boneName) {
	TOIMPLEMENT
	return 0;
}

qboolean G2API_StopBoneAnglesIndex(CGhoul2Info * ghlInfo, const int index) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_StopBoneAnimIndex(CGhoul2Info * ghlInfo, const int index) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetBoneAnglesIndex( CGhoul2Info * ghlInfo, const int index, const vec3_t angles, const int flags, const Eorientations yaw, const Eorientations pitch, const Eorientations roll, qhandle_t * modelList, int blendTime, int currentTime ) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetBoneAnglesMatrixIndex(CGhoul2Info * ghlInfo, const int index, const mdxaBone_t &matrix, const int flags, qhandle_t * modelList, int blendTime, int currentTime) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_DoesBoneExist(CGhoul2Info_v& ghoul2, int modelIndex, char const * boneName) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SetBoneAnimIndex(CGhoul2Info * ghlInfo, const int index, const int startFrame, const int endFrame, const int flags, const float animSpeed, const int currentTime, const float setFrame, const int blendTime) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_SaveGhoul2Models(CGhoul2Info_v &ghoul2, char * * buffer, int * size) {
	TOIMPLEMENT
	return qfalse;
}

void G2API_LoadGhoul2Models(CGhoul2Info_v &ghoul2, char * buffer) {
	TOIMPLEMENT
}

void G2API_LoadSaveCodeDestructGhoul2Info(CGhoul2Info_v &ghoul2) {
	TOIMPLEMENT
}

void G2API_FreeSaveBuffer(char * buffer) {
	TOIMPLEMENT
}

char * G2API_GetAnimFileNameIndex(qhandle_t modelIndex) {
	TOIMPLEMENT
	return va("%s", "not implemented");
}

int G2API_GetSurfaceRenderStatus(CGhoul2Info_v& ghoul2, int modelIndex, char const * surfaceName) {
	TOIMPLEMENT
	return 0;
}

void G2API_CopySpecificG2Model(CGhoul2Info_v &ghoul2From, int modelFrom, CGhoul2Info_v &ghoul2To, int modelTo) {
	TOIMPLEMENT
}

void G2API_DuplicateGhoul2Instance(CGhoul2Info_v &g2From, CGhoul2Info_v * * g2To) {
	TOIMPLEMENT
}

void G2API_AbsurdSmoothing(CGhoul2Info_v &ghoul2, qboolean status) {
	TOIMPLEMENT
}


void G2API_SetRagDoll(CGhoul2Info_v &ghoul2,CRagDollParams * parms) {
	TOIMPLEMENT
}

void G2API_ResetRagDoll(CGhoul2Info_v &ghoul2) {
	TOIMPLEMENT
}

void G2API_AnimateG2ModelsRag(CGhoul2Info_v &ghoul2, int AcurrentTime,CRagDollUpdateParams * params) {
	TOIMPLEMENT
}

qboolean G2API_RagPCJConstraint(CGhoul2Info_v &ghoul2, char const * boneName, vec3_t min, vec3_t max) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RagPCJGradientSpeed(CGhoul2Info_v &ghoul2, char const * boneName, const float speed) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RagEffectorGoal(CGhoul2Info_v &ghoul2, char const * boneName, vec3_t pos) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_GetRagBonePos(CGhoul2Info_v &ghoul2, char const * boneName, vec3_t pos, vec3_t entAngles, vec3_t entPos, vec3_t entScale) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RagEffectorKick(CGhoul2Info_v &ghoul2, char const * boneName, vec3_t velocity) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_RagForceSolve(CGhoul2Info_v &ghoul2, qboolean force) {
	TOIMPLEMENT
	return qfalse;
}


qboolean G2API_SetBoneIKState(CGhoul2Info_v &ghoul2, int time, char const * boneName, int ikState, sharedSetBoneIKStateParams_t * params) {
	TOIMPLEMENT
	return qfalse;
}

qboolean G2API_IKMove(CGhoul2Info_v &ghoul2, int time, sharedIKMoveParams_t * params) {
	TOIMPLEMENT
	return qfalse;
}

void G2API_AttachInstanceToEntNum(CGhoul2Info_v &ghoul2, int entityNum, qboolean server) {
	TOIMPLEMENT
}

void G2API_ClearAttachedInstance(int entityNum) {
	TOIMPLEMENT
}

void G2API_CleanEntAttachments(void) {
	TOIMPLEMENT
}

qboolean G2API_OverrideServerWithClientData(CGhoul2Info_v& ghoul2, int modelIndex) {
	TOIMPLEMENT
	return qfalse;
}

void G2_ConstructGhoulSkeleton( CGhoul2Info_v &ghoul2,const int frameNum,bool checkForNewOrigin,const vec3_t scale) {
	TOIMPLEMENT
}


qboolean G2API_SkinlessModel(CGhoul2Info_v& ghoul2, int modelIndex) {
	TOIMPLEMENT
	return qfalse;
}

#ifdef _G2_GORE
int G2API_GetNumGoreMarks(CGhoul2Info_v& ghoul2, int modelIndex) {
	TOIMPLEMENT
	return 0;
}

void G2API_AddSkinGore(CGhoul2Info_v &ghoul2,SSkinGoreData &gore) {
	TOIMPLEMENT
}

void G2API_ClearSkinGore ( CGhoul2Info_v &ghoul2 ) {
	TOIMPLEMENT
}

#endif // _SOF2

int G2API_Ghoul2Size ( CGhoul2Info_v &ghoul2 ) {
	TOIMPLEMENT
	return 0;
}

char const * G2API_GetModelName ( CGhoul2Info_v& ghoul2, int modelIndex ) {
	TOIMPLEMENT
	return va("%s", "not implemented");
}
