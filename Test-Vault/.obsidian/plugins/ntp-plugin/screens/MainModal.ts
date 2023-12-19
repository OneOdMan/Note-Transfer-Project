import { App, ButtonComponent, Modal } from "obsidian";

export class MainModal extends Modal {
  constructor(app: App) {
    super(app);
  }

  onOpen(){
    new ButtonComponent(this.modalEl)
      .setButtonText("Sync Vault");
  }

  onClose(){
    const {containerEl} = this;
    containerEl.empty();
  }
}