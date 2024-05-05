const app = angular.module("app", []);

app.controller("FormController", ["$scope", $scope => {
    $scope.submit = function() {
        const username = $scope.username;
        const password = $scope.password;
        if(!username || username?.length == 0) alert("Enter username");
        else if(username?.length < 3) alert("Username too short");
        else {
            if(!password || password?.length < 8) alert("Password too short");
            alert("Valid username");
        }
    }
}])