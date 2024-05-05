const app = angular.module("app", ["ngRoute"]);

app.config(["$routeProvider", $routeProvider => {
     $routeProvider
        .when("/home", {
            template: `
                <h2>Homepage</h2>
            `.trim()
        })
        .when("/form", {
            templateUrl: "./views/form.html"
        })
        .otherwise({
            redirectTo: "/home"
        })
}]);