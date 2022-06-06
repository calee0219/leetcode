class MedianFinder:

    def __init__(self):
        self.minHeap = list()
        self.maxHeap = list()

    def addNum(self, num: int) -> None:
        heapq.heappush(self.minHeap, num)
        minNum = heapq.heappop(self.minHeap)
        heapq.heappush(self.maxHeap, -minNum)
        if len(self.maxHeap) - len(self.minHeap) == 2:
            minNum = heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, -minNum)

    def findMedian(self) -> float:
        if len(self.maxHeap) > len(self.minHeap):
            return -self.maxHeap[0]
        return (self.minHeap[0] - self.maxHeap[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()