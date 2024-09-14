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
