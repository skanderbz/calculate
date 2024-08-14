#!/bin/bash

# Ensure the script is run with sudo/root privileges
if [ "$(id -u)" -ne 0 ]; then
    echo "This script must be run as root. Use sudo."
    exit 1
fi

# Compile the calculate program if necessary
if [ ! -f calculate ]; then
    echo "Compiling the calculate program..."
    make
fi

# Ensure the executable exists
if [ ! -f calculate ]; then
    echo "Error: The calculate executable was not found."
    exit 1
fi

# Define the install path
install_path="/usr/local/bin/calculate"

# Copy the calculate binary to /usr/local/bin/
echo "Installing calculate to $install_path"
cp calculate "$install_path"
chmod +x "$install_path"

# Install the calculate binary directly
echo "Installation complete. All users can now run 'calculate' from any directory."
