import axios from 'axios'

const ntp_api_url = "";

export class VaultRegister{
    // Sends a connection message asking to register a vault
    sendRegisterRequest(){
        axios.post(ntp_api_url, {
            message: 'Register_Vault'
        })
        .then(function (response){
            console.log(response);
        })
        .catch(function(error){
            console.log(error);
        });
    }
    // Sends the Vault information
    // Sends a connection message asking to unregister a vault 
}