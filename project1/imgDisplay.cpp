/*
    Chuhan Ren
    January 2025
    CS 5330 Project 1
    Read and display image
*/
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cstring> // gives me strcpy

int main(int argc, char *argv[])
{
    cv::Mat src;
    cv::Mat dst;
    char filename[256];
    // check for a command line argument
    if (argc < 2)
    {
        printf("usage: %s <image filename>\n", argv[0]); // argv[0] ivs the program name
        exit(-1);
    }
    strncpy(filename, argv[1], 255); // safe strcpy
    src = cv::imread(filename);      // by default, returns image as 8-bit BGR image (if

    if (src.data == NULL)
    { // no data, no image
        printf("error: unable to read image %s\n", filename);
        exit(-2);
    }
    cv::imshow(filename, src);
    while (true)
    {
        int key = cv::waitKey(0);

        if (key == 'q')
        {
            printf("Terminating\n");
            break;
        }
        else if (key == 's')
        {
            printf("Saving the image");
            cv::imwrite(filename, dst);
        }
    }
    cv::destroyAllWindows();
    return 0;
}