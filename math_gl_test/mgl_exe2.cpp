#include <mgl2/fltk.h>

int graph(mglGraph *gr) {
    gr->Title("MathGL Demo");
    gr->SetOrigin(0, 0);
    gr->SetRanges(0, 10, -2.5, 2.5);
    gr->FPlot("sin(1.7*2*pi*x) + sin(1.9*2*pi*x)", "r-4");
    gr->Axis();
    gr->Grid();
    return 0;
}

int main() {
    mglFLTK gr(graph, "MathGL demo window title");
    return gr.Run();
}