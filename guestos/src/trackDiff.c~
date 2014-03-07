#include <stdio.h>
#include <assert.h>

int IOCost(int blockNo, int nHeads, int nTracks, int nSectors, int curTrackNo, int curSectorNo, int trackCost, int sectorCost) {
	int headNo = blockNo/(nTracks*nSectors);
	int platterBlockNo = blockNo%(nTracks*nSectors);
	int trackNo = platterBlockNo/(nSectors);
	blockNo = platterBlockNo%(nSectors);
	int cost = ((blockNo - curSectorNo) >= 0)? (blockNo - curSectorNo)*sectorCost: (nSectors + blockNo - curSectorNo)*sectorCost;
	cost += ((trackNo - curTrackNo) >= 0)? (trackNo - curTrackNo)*trackCost: (curTrackNo - trackNo)*trackCost;
}

int main() {
	return 0;
}
