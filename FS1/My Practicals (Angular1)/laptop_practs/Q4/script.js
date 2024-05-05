const app = angular.module("app", []);

app.controller("MainController", ["$scope", $scope => {
    $scope.showAlert = _ => alert("Alert Message!");
}]);