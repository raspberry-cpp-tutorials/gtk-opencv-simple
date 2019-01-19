set path+=src/**10              " For 'gf', looks in current folder, and up to 10 level of sub-sub-folders
set hidden                      " For 'gf', let's you go to next file without requiring to save current.                 
set cindent shiftwidth=4        " In C/C++, size of the tabulation increase each time you have a {
set cinoptions=i0,g0
set tabstop=4                   " In all files, size of the Tab
set expandtab                   " Use spaces instead of Tab
autocmd vimenter * NERDTreeVCS  " Automatically opens NERDTree
let g:ConqueTerm_StartMessages = 0
let g:ConqueTerm_Color = 0
let g:ConqueTerm_CloseOnEnd = 1
let g:ConqueTerm_Interrupt = '<C-g><C-c>'
let g:ConqueTerm_ReadUnfocused = 1
let g:ycm_autoclose_preview_window_after_insertion = 1  "For YouCompleteMe to close the preview window
let g:ycm_autoclose_preview_window_after_completion = 1 "after the completion is finished.
