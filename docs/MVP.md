# MVP Base Interface Setup
MVP decouples view(UI) and business logic into two software parts. This allows us to apply clean structure, apply unit testing, allow developers to focus on specif problem e.g. UI or business logic.

* Module holds data that are processed by presenter and displayed by view.
* View focuses on UI, this is the graphical part (buttons, animations, text fields etc.).
* Presenter acts as middleman, it directs data from module to view, and also updates module's fields if changes are capered via UI.

In order to implement MVP in application we need to `publisher / subscriber` interface. MVP Base interface provides 3 main interfaces and class, listed below, which handler communication between components.

* `BaseMvp::IBaseNotificationType`: Notification interface allow sender to encapsulate data and receiver to differentiate between different notifications.
* `BaseMvp::BasePublisher`: Publisher central point of communication, handles data distribution and includes main business logic.
* `BaseMvp::BaseSubscriber`: Subscriber allows to subscribe to publisher an receive notifications, in bi-directional communication subscriber is also able to send notifications to publisher
