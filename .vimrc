set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set colorcolumn=110
highlight ColorColumn ctermbg=darkgray
augroup project
    autocmd!
    autocmd BufRead,BufNewFile *.h,*.cpp set filetype=cpp.doxygen
augroup END
set makeprg=make
nnoremap <F4> :make!<cr>
nnoremap <F5> :!./printer<cr>
execute pathogen#infect()
syntax on
filetype plugin indent on
" Customize the settings for vim-template plugin
let g:email = "reinout91@gmail.com"
let g:user = "Reinout Holtrup"
let g:license = "Free to use"
autocmd VimEnter * NERDTree
autocmd VimEnter * wincmd p
autocmd VimEnter * TagbarToggle
:set mouse=a

