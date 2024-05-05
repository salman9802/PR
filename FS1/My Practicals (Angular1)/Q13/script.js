const app = angular.module("app", ["ngRoute"]);
        
        app.config(["$routeProvider", $routeProvider => {
            $routeProvider
                .when("/home", {
                    template: `
                        <h1>Homepage</h1>
                    `.trim()
                })
                .when("/about", {
                    template: `
                        <h1>About Us</h1>
                    `.trim()
                })
                .otherwise({
                    redirectTo: "/home"
                });
        }]);

        app.controller("MainController", ["$scope", "$location", ($scope, $location) => {
            $scope.currentLoc = "";

            $scope.setLoc = function() {
                $scope.currentLoc = $location.absUrl()
            }
        }]);