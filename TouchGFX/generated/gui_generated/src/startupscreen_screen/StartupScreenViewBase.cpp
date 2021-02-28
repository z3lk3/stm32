/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/startupscreen_screen/StartupScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

StartupScreenViewBase::StartupScreenViewBase()
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    Background.setXY(0, 0);
    Background.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_ID));

    circleProgress.setXY(148, 89);
    circleProgress.setProgressIndicatorPosition(0, 0, 184, 94);
    circleProgress.setRange(0, 4095, 4095, 0);
    circleProgress.setCenter(92, 92);
    circleProgress.setRadius(82);
    circleProgress.setLineWidth(16);
    circleProgress.setStartEndAngle(-90, 90);
    circleProgress.setCapPrecision(90);
    circleProgress.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_LARGE_CIRCLE_INDICATOR_BG_LINE_HALF_ID));
    circleProgressPainter.setBitmap(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_FILL_LARGE_CIRCLE_INDICATOR_FILL_LINE_HALF_ID));
    circleProgress.setPainter(circleProgressPainter);
    circleProgress.setValue(60);

    textArea.setXY(194, 202);
    textArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea.setLinespacing(0);
    textArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID1));

    animatedImage1.setXY(8, 9);
    animatedImage1.setBitmaps(BITMAP_ANI_01_ID, BITMAP_ANI_11_ID);
    animatedImage1.setUpdateTicksInterval(6);
    animatedImage1.startAnimation(false, true, true);

    add(__background);
    add(Background);
    add(circleProgress);
    add(textArea);
    add(animatedImage1);
}

void StartupScreenViewBase::setupScreen()
{

}
