What is a Smart Contract?

A smart contract is a self-executing contract with the terms of the agreement directly written into lines of code. On the Ethereum blockchain, smart contracts run as decentralized programs. For this tutorial, we'll create a smart contract that represents a basic token with functionalities like minting, transferring, and checking balances.
Step 1: Install MetaMask

MetaMask is a browser extension that allows you to manage your Ethereum account and interact with Ethereum-based applications (DApps). You'll use MetaMask to interact with your smart contract and deploy it on the Ropsten Test Network.
1.1 Install MetaMask:

    Go to MetaMask's official website.
    Install the browser extension for your browser (Chrome, Firefox, Brave, or Edge).
    After installing, click on the MetaMask extension in your browser.

1.2 Set Up MetaMask:

    Click "Get Started."
    If you don’t have a MetaMask account, click "Create a Wallet." Follow the prompts to set up a new wallet.
    Store your seed phrase in a safe place (don’t share this with anyone). This is your recovery phrase.
    Create a strong password for MetaMask.
    After setting up, you’ll see your Ethereum address (a long string starting with "0x").

1.3 Switch to Ropsten Test Network:

The Ropsten Test Network allows you to deploy contracts without spending real Ether.

    Open MetaMask and click the network dropdown at the top (by default, it will say "Ethereum Mainnet").
    From the dropdown, select Ropsten Test Network.

1.4 Get Ropsten Test Ether:

To deploy smart contracts, you’ll need some test Ether, which is free.

    Visit a Ropsten faucet like this one.
    Paste your MetaMask Ethereum address (which you can copy by clicking your account name in MetaMask) into the faucet’s input box and request Ether.
    After a few moments, your Ropsten Ether will appear in your MetaMask wallet.

Step 2: Access Remix IDE

Remix IDE is a web-based integrated development environment (IDE) for writing and deploying Ethereum smart contracts using Solidity.
2.1 Open Remix:

    Go to Remix IDE.
    You’ll see a file explorer on the left, an editor in the center, and various tools on the right.

2.2 Create a New Solidity File:

    In the left panel (File Explorer), click on the "+" icon or right-click the contracts folder, and select "New File."
    Name the file BasicToken.sol (you can name it anything you like, but .sol is the extension for Solidity files).

Step 3: Write the Smart Contract

We'll write a simple token smart contract in Solidity. The contract allows for minting new tokens, transferring tokens, and checking balances.
3.1 Write the given code in metamask
Explanation of the Code:

    balances: This stores the number of tokens for each Ethereum address.
    totalSupply: Keeps track of the total number of tokens in circulation.
    mint: Allows the contract owner to create new tokens and assign them to a specific address.
    transfer: Lets users transfer tokens to other addresses.
    Events (Transfer, Mint): These events are used to record transactions on the blockchain, making them traceable and visible.

Step 4: Compile the Smart Contract

After writing the smart contract, we need to compile it to check for errors.

    On the left panel, click the Solidity Compiler icon (a green checkmark).
    In the Solidity compiler tab:
        Ensure that the compiler version is set to 0.8.0 or later (as indicated by pragma solidity ^0.8.0 in the contract).
        Click Compile BasicToken.sol.
    If the contract compiles successfully, you’ll see a green checkmark and no errors.

Step 5: Deploy the Smart Contract on the Ropsten Test Network

Now, it’s time to deploy the contract onto the Ethereum Ropsten Test Network.
5.1 Connect MetaMask to Remix:

    Click the Deploy & Run Transactions icon on the left panel (Ethereum logo).
    Under Environment, choose Injected Web3 (this connects Remix to your MetaMask).
    A MetaMask pop-up will appear asking for confirmation to connect Remix to your MetaMask account. Click Confirm.

5.2 Deploy the Contract:

    After connecting to MetaMask, your account address and balance will appear in Remix.
    Click the Deploy button to deploy the contract.
    MetaMask will pop up, asking you to confirm the transaction (this transaction uses Ropsten test Ether). Click Confirm.
    Wait for the transaction to be mined (this can take a few seconds to a minute). You’ll see a confirmation in Remix once the contract is deployed.

Step 6: Interact with the Deployed Smart Contract

Once your contract is deployed, you can interact with it directly from Remix. You’ll find your contract in the Deployed Contracts section.
6.1 Mint New Tokens:

    In the Deployed Contracts section, find the mint function.
    Enter an Ethereum address (e.g., your MetaMask address) in the account field and a number (e.g., 1000) in the amount field.
    Click Transact.
    MetaMask will ask you to confirm the transaction. Confirm it.

Now, you have minted 1000 tokens to the specified address.
6.2 Transfer Tokens:

    In the Deployed Contracts section, find the transfer function.
    Enter the recipient address (the address to send tokens to) and the amount of tokens to transfer.
    Click Transact.
    MetaMask will ask for confirmation. Confirm the transaction.

Now, you’ve transferred tokens from one address to another.
6.3 Check Balance:

    In the Deployed Contracts section, find the balanceOf function.
    Enter an Ethereum address to check its token balance.
    Click Call to see the balance of that address.

Step 7: Verify the Smart Contract on Etherscan

Once your contract is deployed, you can verify it on the Ropsten Etherscan to make it publicly viewable.
7.1 Verify the Contract:

    Go to Ropsten Etherscan.
    Search for the contract address (you’ll find this in Remix after deployment).
    Click the Verify and Publish option on Etherscan.
    Submit the contract's source code from Remix to make it visible to anyone who visits the contract’s page on Etherscan.

Recap of the Steps:

    Set up MetaMask and get test Ether from a Ropsten faucet.
    Open Remix IDE and write the Solidity smart contract.
    Compile the contract to check for any errors.
    Deploy the contract on the Ropsten Test Network using MetaMask.
    Interact with the deployed contract by minting tokens, transferring tokens, and checking balances.
    Optionally, verify the contract on Ropsten Etherscan.
