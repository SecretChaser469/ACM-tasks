Step 1: Set Up the Web Server Using EC2
1.1 Create an AWS Account

    Go to AWS and sign up for a free account.
    You’ll need to enter your payment information, but there’s a free tier for many services.

1.2 Launch an EC2 Instance (Your Web Server)

An EC2 instance is basically a computer in the cloud that runs your website.

    Go to EC2:
        After logging into AWS, search for "EC2" in the AWS dashboard search bar and click on it.

    Launch a Virtual Machine:
        Click “Launch Instance” (this is the technical term for starting up a cloud computer).

    Choose a Template (AMI):
        Select Amazon Linux or Ubuntu from the list (these are popular Linux-based operating systems).

    Choose Instance Type:
        For a simple website, the free-tier t2.micro instance type is enough. Select this option.

    Configure Security Group:
        This step decides who can access your web server.
        Ensure you allow:
            SSH (port 22) – This allows you to access your server securely.
            HTTP (port 80) – This allows people to visit your website.

    Launch the Instance:
        AWS will ask you to create a key pair. This key pair is a security file that you’ll need to access the server. Download the .pem file and keep it safe (you’ll need it soon).
        Click "Launch."

    Find Your Instance:
        After the instance is launched, go to the EC2 dashboard and find your instance’s public IP address. This is the address you’ll use to connect to your server.

1.3 Connect to Your EC2 Instance

    You’ll now connect to your instance using SSH (a secure way to access the cloud server).

    Open your terminal (Mac/Linux) or use software like PuTTY (Windows).

    Connect with SSH:
        If you’re on Mac/Linux, use this command (replace your-key.pem and your-ec2-public-ip with your own info):

      

        ssh -i "your-key.pem" ec2-user@your-ec2-public-ip

        If you’re using Windows, use the PuTTY program and follow instructions to connect.

    You’re In! Now you're connected to your cloud server.

1.4 Install Web Server Software

Your website needs software to show your web pages to people. Apache or Nginx are good options.

    Install Apache (this is the program that will handle website traffic):

   

sudo yum install httpd -y  # for Amazon Linux
sudo apt install apache2 -y  # for Ubuntu

Start the Web Server:



    sudo systemctl start httpd  # for Amazon Linux
    sudo systemctl start apache2  # for Ubuntu

    Test Your Server:
        Open your browser and type your EC2 public IP address. You should see a welcome page, meaning the server is running!

Step 2: Set Up S3 for Storing Static Files (Optional but Useful)

S3 is a storage service where you can keep images, videos, or other files for your website.
2.1 Create an S3 Bucket

    Go to the S3 service from the AWS dashboard.
    Click "Create Bucket."
    Choose a unique name for your bucket (e.g., my-website-bucket) and select your region.
    Leave everything else as default and click "Create."

2.2 Upload Files

    Upload any files (images, CSS files, etc.) that your website needs.
    Make sure the files are public, so people can access them.

2.3 Access Your Files

    Each file in S3 has a URL like this:



    https://your-bucket-name.s3.amazonaws.com/your-file-name

    Use these URLs in your website code to display images or other files.

Step 3: Set Up a Domain Name with Route 53

Route 53 is a service that helps you connect your website to a custom domain name (like www.mywebsite.com).
3.1 Buy a Domain (or Use an Existing One)

    Go to Route 53 in the AWS dashboard.
    Click "Register Domain" to buy a new domain name (e.g., mywebsite.com).
    If you already own a domain, you can transfer it to AWS or just set it up here.

3.2 Create a Hosted Zone

    After you get your domain, go back to Route 53 and click "Create Hosted Zone."
    Enter your domain name (e.g., mywebsite.com).
    AWS will generate name servers for your domain.

3.3 Set Up DNS Records

    In Route 53, create a new A Record:
        Name: Leave blank or type "www."
        Type: A (for the IPv4 address).
        Value: Paste your EC2 instance’s public IP address here.
    Save the changes, and your domain will now point to your web server!

Step 4: Secure Your Application
4.1 Set Up IAM Roles (Permissions for Your Server)

    Go to the IAM (Identity and Access Management) service.
    Create a role for your EC2 instance. This role gives your instance permissions to do things like read from S3.
    Attach this role to your EC2 instance.

4.2 Enable HTTPS (Secure Connection)

To ensure your website is secure (uses HTTPS), you can use AWS’s free SSL certificates:

    Go to the AWS Certificate Manager (ACM) and request a new certificate for your domain.
    Validate the domain using Route 53 (follow the steps AWS provides).
    Once the certificate is ready, configure your web server to use HTTPS. For Apache, you'll need to modify the server settings to listen on port 443 (HTTPS).
                                 
