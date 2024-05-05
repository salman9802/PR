const app = angular.module("app", []);

app.controller("MainController", ["$scope", $scope => {
    $scope.students = [
        {
            name: "John",
            age:15
        },
        {
            name: "Sam",
            age:25
        },
        {
            name: "Josh",
            age:22
        },
    ];
}]);