class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);
        int area3=max(min(bx2,ax2)-max(ax1,bx1),0)*max(min(by2,ay2)-max(by1,ay1),0);
        return area1+area2-area3;
    }
};