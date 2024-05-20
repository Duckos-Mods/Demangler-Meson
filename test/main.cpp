#include <print>
#include <demangler/Demangle.h>

int main()
{
    std::println("Hello World!");
    auto thing = demangler::demangle_invalid_args;
    auto demangled = demangler::itaniumDemangle("_ZN21BuriedTreasureFeature26getNearestGeneratedFeatureER9DimensionR11BiomeSourceRK8BlockPosRS4_");
    std::println("Demangled: {}", demangled);
}