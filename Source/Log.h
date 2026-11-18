#pragma once
#include <juce_core/juce_core.h>

// Tiny crash-hunting log: Documents/STEINEX/TRANSIT FX/log.txt
namespace steinex
{
inline void logLine (const juce::String& s)
{
    try
    {
        auto f = juce::File::getSpecialLocation (juce::File::userDocumentsDirectory)
                    .getChildFile ("STEINEX").getChildFile ("TRANSIT FX").getChildFile ("log.txt");
        f.getParentDirectory().createDirectory();
        if (f.getSize() > 200000) f.deleteFile();
        f.appendText (juce::Time::getCurrentTime().toString (true, true, true, true) + "  " + s + "\n");
    }
    catch (...) {}
}
}
