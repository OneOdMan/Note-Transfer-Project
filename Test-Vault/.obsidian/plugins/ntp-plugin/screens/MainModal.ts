import { App, ButtonComponent, Modal } from "obsidian";

export class MainModal extends Modal {
  constructor(app: App) {
    super(app);
  }

  onOpen(){
    new ButtonComponent(this.containerEl)
      .setButtonText("Sync Vault")
      .onClick(() => {
        // Starts the syncing process for this current vault
      });
  }
}