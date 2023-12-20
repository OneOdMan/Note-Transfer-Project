import { App, ButtonComponent, Modal } from "obsidian";

export class MainModal extends Modal {
  constructor(app: App) {
    super(app);
  }

  onOpen(){
    // Button for syncing the vault
    new ButtonComponent(this.modalEl)
      .setButtonText("Sync Vault");
    // Button for registering the vault
    new ButtonComponent(this.modalEl)
      .setButtonText("Register Vault");
  }

  onClose(){
    const {containerEl} = this;
    containerEl.empty();
  }
}