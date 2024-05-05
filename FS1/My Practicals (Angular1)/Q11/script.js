const app = angular.module("app", []);

app.controller("MainController", ["$scope", "$interval", ($scope, $interval) => {
    const intervalFunc = _ => {
        const current = new Date();

        $scope.currentDate = current.toLocaleDateString();
        $scope.currentTime = current.toLocaleTimeString();
    };

    $interval(intervalFunc, 1000);
}]);