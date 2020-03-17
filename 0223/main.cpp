class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E>=C || A>=G || B>=H || F>=D) return (C-A)*(D-B) + (G-E)*(H-F);
        int width, height;
        if(E>A) {
            if(G>C) {
                width = C - E;
            } else {
                width = G - E;
            }
        } else {
            if(C>G) {
                width = G - A;
            } else {
                width = C - A;
            }
        }
        if(F>B) {
            if(H>D) {
                height = D - F;
            } else {
                height = H - F;
            }
        } else {
            if(D>H) {
                height = H - B;
            } else {
                height = D - B;
            }
        }
        return (C-A)*(D-B) - width*height + (G-E)*(H-F) ;

/*
        int area1 = (C-A)*(D-B), area2 = (G-E)*(H-F);
        if(A>=G||B>=H||C<=E||D<=F)return area1+area2;
        int tx = min(C,G), ty=min(D,H);
        int bx = max(A,E), by=max(B,F);
        return area1-(tx-bx)*(ty-by)+area2;
*/
    }
};