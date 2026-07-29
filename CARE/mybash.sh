#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias grep='grep --color=auto'
PS1='[\u@\h \W]\$ '

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
alias godot='/home/sasi/Downloads/Godot_v4.6-stable_linux.x86_64'
alias blender="/home/sasi/Softwares/blender-5.0.1-linux-x64/blender"
. "$HOME/.cargo/env"


# Function to start a specific development environment
function cp() {
    local project_path="/home/sasi/cp"

    # 1. Change Directory (cd)
    echo "--- Navigating to $project_path ---"
    cd "$project_path" || {
        echo "Error: Directory $project_path not found."
        return 1
    }

    # 2. Execute the Application
    # We use `konsole` here because it forces the GUI app to open
    # in a separate, clean terminal window, leaving the current shell prompt active.
    echo "--- Launching application ---"
    konsole -e code . &

    echo "✅ Project started and application launched!"
}



# Function to start a specific development environment
function care() {
    local project_path="/home/sasi/cp/CARE"

    # 1. Change Directory (cd)
    echo "--- Navigating to $project_path ---"
    cd "$project_path" || {
        echo "Error: Directory $project_path not found."
        return 1
    }

    konsole -e brave -newtab "/home/sasi/Downloads/Third Year_Instruction Book _ Placement Readiness -1.pdf" "https://claude.ai"

    # 2. Execute the Application
    # We use `konsole` here because it forces the GUI app to open
    # in a separate, clean terminal window, leaving the current shell prompt active.
    echo "--- Launching application ---"
    konsole -e code . &

    echo "✅ Project started and application launched!"
}

