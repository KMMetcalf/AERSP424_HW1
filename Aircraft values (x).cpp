
// This is the data for the Approach speed, Wingspan, and Maximum take-off weight of aircraft models and their given Engine types

  // M-346 Master
  x = [124, 31.89, 20.945]; //Approach speed, Wingspan, MTOW
  y = [1]; //Turbojet

  // AT-402B
  x = [74, 51.08, 9.170];
  y = [0]; //Turboprop

  // MB-326
  x = [103, 34.67, 8.300]
  y = [1]; //Turbojet

  //AT-502B
  x = [77, 52.00, 9.400];
  y = [0]; //Turboprop  

  //MB-339
  x = [104, 35.63, 13.000];
  y = [1]; //Turbojet

  //AT-602
  x = [92, 56.00, 9.400];
  y = [0]; //Turboprop  

  //Aero L-159 Alca
  x = [130, 31.29, 17.637];
  y = [1]; //Turbojet

  //AT-504
  x = [73, 52.00, 9.600];
  y = [0]; //Turboprop 
// -----------------------------------------------------------------------------------------------------------------

//Question 9

  double w = wi; // w from question 8
  double y = 1; //1 is a placeholder for the type of engine

for (int i = 1; i <= 4; ++i) {
  // code block to be executed
  
//SF50 Vision
if(i = 1)
{
  x = [87.0, 38.67, 6.000];
EngineDetermination();
  return 0;
}

//208 Caravan
if(i = 2)
{
  x = [79.0, 52.08, 8.000];
EngineDetermination();
return 0;
}

if(i = 3)
{
//Aero L-29 Delfin
  x = [92.0, 33.75, 7.804]; 
EngineDetermination();
return 0;
}

if(i = 4)
{
//AT-802U
  x = [91.0, 59.25, 16.000];
EngineDetermination();
return 0;
}

void EngineDetermination() {  //function to determine which engine type the plane posesses

//math to find y to determine engine type 

if (y > 0.5) {
  cout << "The engine type of a " << airplane << "is a Jet Engine" << endl;
if (y < 0.5) {
cout << "The engine type of a " << airplane << "is a Turbo Prop" << endl;
else
  cout << "This plane doesn't work." << endl;
}

}

