import os

def check_linefeed_in_text_files(directory='.'):
    # Traverse all files, but ignore the .git directory
    for root, dirs, files in os.walk(directory):
        if '.git' in dirs:
            dirs.remove('.git')

        for file in files:
            file_path = os.path.join(root, file)

            # Open the file in binary mode to check if it's a text file
            try:
                with open(file_path, 'rb') as f:
                    content = f.read()  # Read the entire file content
                    content.decode('utf-8')  # Attempt to decode as text

                    # If it’s a text file, check if it ends with a newline
                    if not content.endswith(b'\n'):
                        print(f"{file_path}: No trailing newline")
            except UnicodeDecodeError:
                # Skip if it’s not a text file
                continue

# Run in the current directory
check_linefeed_in_text_files()
