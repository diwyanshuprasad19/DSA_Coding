10 Design Patterns for SDE-2 with Real Scenarios
Pattern	Use When	Real Scenario
Factory	Object creation depends on type	Payment: UPI/Card/Wallet/NetBanking
Strategy	Logic changes based on condition	Discount logic, sorting logic, pricing logic
Observer	One event should notify multiple systems	Order placed → email, SMS, inventory update
Singleton	Only one shared instance is needed	Logger, config manager, DB connection pool
Builder	Object has many optional fields	Creating complex request/user/profile object
Adapter	Third-party API format does not match your app	Razorpay/Stripe/PayU integration
Decorator	Add extra behavior without changing main code	Logging, caching, authorization wrapper
Facade	Hide complex internal flow behind simple method	placeOrder() handles cart, payment, inventory
Command	Treat actions as objects	Undo/redo, job queue, task execution
Template Method	Common flow same, some steps different	Report generation: PDF/Excel/CSV