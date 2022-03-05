"================ Basic Requirments ========================
"To set the syntax highlighting
syntax on

"To set the line numbers
set number

"To enable the last status
set laststatus=2

"To wrap the text in the window
set wrap

"To set the particular encoding
set encoding=utf-8

"To set the proper tabs and auto-indentation 
set tabstop=4 softtabstop=4
set shiftwidth=4
set expandtab
set smartindent
set autoindent


"For smart searching
set ignorecase
set smartcase
set incsearch

"Don't know the proper use of it
set noswapfile

"Set the Cut, copy paste register as +register
"set clipboard=unnamedplus

"To set the cursor 12lines off from the top and bottom
set scrolloff=12

highlight ColorColumn ctermbg=0 guibg=lightgrey
set background=dark

"For Autocompletion and give better suggestions
set complete+=kspell
set completeopt=menuone,longest
set shortmess+=c

"<<== Some Keybindings =====>>
"Keybinding to select everything in the editor via ctrl + a
map <C-a> <esc>ggVG<CR>

"Keybinding for copy into the + register by Ctrl + y
map <C-y> "+y

"Keybinding to paste from + register by Ctrl + p
map <C-p> "+p

"Keybinding for brackets autocompetion: { + enter => {}
inoremap {<CR>  {<CR>}<Esc>O
inoremap {}     {}

"Keybinding for moving from insert mode to normal mode using 'jk'
imap jk         <Esc>

"============== Basic requirements ends here ===============
"https://github.com/junegunn/vim-plug
"To install the plugins: Move to command mode and run:=> :PlugInstall

call plug#begin('~/.vim/plugged')

Plug 'morhetz/gruvbox'
Plug 'jremmen/vim-ripgrep'
Plug 'tpope/vim-fugitive'
Plug 'leafgarland/typescript-vim'
Plug 'vim-utils/vim-man'
Plug 'lyuts/vim-rtags'
Plug 'vim-scripts/AutoComplPop'
"Plug  'octol/vim-cpp-enhanced-highlight'
"Plug 'https://github.com/kien/ctrlp.vim.git '
"Plug 'git@github.com:Valloric/YouCompleteMe.git'
"Plug 'mbill/undotree'
call plug#end()

colorscheme gruvbox


