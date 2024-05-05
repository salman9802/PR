const app = angular.module("app", ["ngRoute"]);

const users = [];

app.config(["$routeProvider", $routeProvider => {
    $routeProvider
        .when("/home", {
            template: "<h1>Homepage</h1>"
        })
        .when("/signup", {
            templateUrl: "./views/signup.html",
            controller: "SignupController"
        })
        .when("/login", {
            templateUrl: "./views/login.html",
            controller: "LoginController"
        })
        // .otherwise({
        //     redirectTo: "/index"
        // });
}]);

app.controller("SignupController", ["$scope", "$location", function($scope, $location) {
    $scope.signupUser = function () {
        const name = $scope.name;
        const password = $scope.password;
        users.push({name, password});
        alert("Signup Successful!");
        // $location.path = "/login";
    }
}]);

app.controller("LoginController", ["$scope", function($scope){
    $scope.loginUser = function () {
        const name = $scope.name;
        const password = $scope.password;
        const userIndex = users.findIndex(user => user.name === name && user.password === password);
        if(userIndex === -1) alert("No user found!");
        else {
            alert("Login Successful!");
            $scope.loggedIn = true;
            // $location.path = "/home";
        }
    }

}]);