#include <iostream>

using namespace std;

int main()
{
    int const inchesToFeet = 12;
    const double inchesToMetters = 0.0254;
    const double poundsToKg = 0.453592;

    int heightFeet, heightInches, weightPounds;
    double heightMetters, weightKg, BMI;

    cout << "Enter your height in feet and inches -> ";
    cin >> heightFeet >> heightInches; // 5 8
    cout << "Enter your weight -> ";
    cin >> weightPounds; // 139

    heightInches = heightInches + heightFeet * inchesToFeet;
    heightMetters = heightInches * inchesToMetters;
    weightKg = weightPounds * poundsToKg;

    BMI = weightKg / pow(heightMetters, 2);

    cout << heightMetters << endl;
    cout << weightKg << endl;
    cout << BMI << endl;

    return 0;
}
