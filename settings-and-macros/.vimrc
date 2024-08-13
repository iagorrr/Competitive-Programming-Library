set sta nu rnu sc cindent
set ts=2 sw=2
set bg=dark ruler clipboard=unnamed,unnamedplus, timeoutlen=100
colorscheme default
syntax on

" Takes the hash of the selected text and put
" in the vim clipboard
function! HashSelectedText()
    " Yank the selected text to the unnamed register
    normal! gvy
    " Use the system() function to call sha256sum with the yanked text
    let l:hash = system('echo ' . shellescape(@@) . ' | sha256sum')
    " Yank the hash into Vim's unnamed register
    let @" = l:hash
endfunction


