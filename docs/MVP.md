# MVP Base Interface Setup
MVP decouples view(UI) and business logic into two losley coupled software parts. This allows us to apply clean structure, apply unit testing, allow developers to focuse on specifc problem e.g. UI development or back-end.

* Module holds data that are processed by presenter and displayed by view.
* View focuses on UI, this is the graphical part (buttons, animations, text fields etc.).
* Presenter acts as middleman, it darects data from module to view, and also updates module's fields if changes are capured via UI.

## Folder structure
MVP Base interface provides 3 main interfaces, `BaseMvp::IBaseNotificationEvent`, `BaseMvp::IBasePresenter` and `BaseMvp::IBaseView`.
