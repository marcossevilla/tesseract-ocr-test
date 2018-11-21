#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"
#include "tesseract/renderer.h"
#include <fstream>
#include <iostream>

using namespace tesseract;
using namespace std;

int main()
{
    char *out_text;
    
    TessBaseAPI *api = new TessBaseAPI();
    // initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    
    // open input image with leptonica library
    Pix *image = pixRead("/Users/msevillam/Downloads/ocrtest.jpg"); // mutable path
    api->SetImage(image);
    
    // Get OCR result
    out_text = api->GetUTF8Text();
    printf("OCR output:\n%s", out_text);
    
    // output file
    ofstream out("/Users/msevillam/Downloads/output.txt");
    out << out_text;
    out.close();
    
    // destroy used object and release memory
    api->End();
    delete [] out_text;
    pixDestroy(&image);
    
    return 0;
}
