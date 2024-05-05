const app = angular.module("app", []);

app.controller("MainController", ["$scope", $scope => {
    $scope.calculateSum = _ => {
        $scope.showSum = true;
        $scope.sum = $scope.n1 + $scope.n2;
    }
}]);