#include "crow.h"
#include "CustomLib/CustomTimeValidation.h"

using namespace crow;

int main()
{
    SimpleApp app;
    const CustomTimeValidation checkTime;

    CROW_ROUTE(app, "/")
        ([] {
                json::wvalue covidData;
                covidData["ok"] = true;
                covidData["data"] = {
                    {"total_positive", 10472847},
                    {"total_recovered", 7274937},
                    {"total_deaths", 3197910},
                    {"total_active", 2839447},
                    {"new_positive", 358463},
                    {"new_recovered", 12443},
                    {"new_deaths", 54},
                    {"new_active", 2743},
                };
                covidData["message"] = "Successfuly retrieve general covid cases information.";


                return response(covidData);
        });

    CROW_ROUTE(app, "/yearly/<int>")
        ([checkTime](int year) {

                bool isValidParams = checkTime.IsValid(year);   //Check if the date/time is valid
                std::string dateTime = "";

                if (isValidParams)
                    dateTime = std::to_string(year);
                else
                    return response(400);

                json::wvalue covidData;
                covidData["ok"] = isValidParams;
                covidData["data"] = {
                    {"year", dateTime},
                    {"positive", 4648293},
                    {"recovered", 3873823},
                    {"deaths", 238372},
                    {"active", 536098},
                };
                covidData["message"] = "Successfuly retrieve yearly data of total covid cases of " + dateTime + ".";


                return response(covidData);
            });

    CROW_ROUTE(app, "/monthly/<int>/<int>")
        ([checkTime](int year, int month) {

                bool isValidParams = checkTime.IsValid(year, month);    //Check if the date/time is valid
                std::string dateTime = "";
                std::string specialMonth = "";

                if (isValidParams)
                {
                    specialMonth = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);  //Adding 0 prefix when converted to a string
                    dateTime = std::to_string(year) + "-" + std::to_string(month);
                }
                else
                    return response(400);

                json::wvalue covidData;
                covidData["ok"] = isValidParams;
                covidData["data"] = {
                    {"month", dateTime},
                    {"positive", 927328},
                    {"recovered", 374622},
                    {"deaths", 3727},
                    {"active", 548979},
                };
                covidData["message"] = "Successfuly retrieve yearly data of total covid cases of " + dateTime + ".";


                return response(covidData);
            });

    CROW_ROUTE(app, "/daily/<int>/<int>/<int>")
        ([checkTime](int year, int month, int date) {

                bool isValidParams = checkTime.IsValid(year, month, date);  //Check if the date/time is valid
                std::string dateTime = "";
                std::string specialMonth = "";
                std::string specialDate = "";

                if (isValidParams)
                {
                    specialMonth = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);  //Adding 0 prefix when converted to a string
                    specialDate = (date < 10) ? "0" + std::to_string(date) : std::to_string(date);      //Adding 0 prefix when converted to a string
                    dateTime = std::to_string(year) + "-" + std::to_string(month) + "-" + specialDate;
                }
                else
                    return response(400);

                json::wvalue covidData;
                covidData["ok"] = isValidParams;

                covidData["data"] = {
                    {"date", dateTime},
                    {"positive", 342},
                    {"recovered", 187},
                    {"deaths", 3},
                    {"active", 152},
                };
                covidData["message"] = "Successfuly retrieve yearly data of total covid cases of " + dateTime + ".";

                return response(covidData);
            });

    app.port(18080).run();
}