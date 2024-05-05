const app = angular.module("app", []);

app.controller("StudentRegistrationController", ["$scope", function($scope) {
    $scope.registerStudent = function() {
        const firstName = $scope.studentFirstName;
        const lastName = $scope.studentLastName;
        const age = parseInt($scope.studentAge);

        const nameRegex = /^[A-Za-z]+$/;
        if(firstName.match(nameRegex) && lastName.match(nameRegex) && age >= 18 && age <=50) {
            const currentHour = new Date().getHours();
            $scope.greeting = currentHour < 12 ? "Good Morning" : "Good Evening";
            $scope.toGreet = true;
        } else {
            alert("Name should only contain alphabets and age should be between 18 and 50.");
        }
    }
}]);