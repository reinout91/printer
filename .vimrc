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
let &path.="src/include,/usr/include/AL,"
"='-I'.substitute(&path, ',', '\n-I', 'g')<cr>p
set makeprg=make\ -C\ ../build\ -j9
nnoremap <F4> :make!<cr>
nnoremap <F5> :!./my_great_program<cr>

