#include <stdio.h>
#include <assert.h>

int IOCost(int blockNo, int nHeads, int nTracks, int nSectors, int curBlockNo, int trackCost, int sectorCost) {
	int headNo = blockNo/(nTracks*nSectors);
	blockNo = blockNo%(nSectors*nTracks);
	int trackNo = blockNo/(nSectors);
	curBlockNo = curBlockNo%(nSectors*nTracks);
	int curTrackNo = curBlockNo/(nSectors);
	int curSectorNo = curBlockNo%(nTracks*nSectors);
	int cost = ((blockNo - curSectorNo) >= 0)? (blockNo - curSectorNo)*sectorCost: (nSectors + blockNo - curSectorNo)*sectorCost;
	cost += ((trackNo - curTrackNo) >= 0)? (trackNo - curTrackNo)*trackCost: (curTrackNo - trackNo)*trackCost;
}

int main() {
	return 0;
}
