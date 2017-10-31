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
set makeprg=make\ -C\ ../build\ -j9
nnoremap <F4> :make!<cr>
nnoremap <F5> :!./printer<cr>

