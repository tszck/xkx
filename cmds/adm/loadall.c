
inherit F_CLEAN_UP;
int help(object me);
int loadall(string dir);

int main(object me, string dir)
{
    if (!dir)
        dir = "/";
    if (dir[ < 1] != '/')
        dir += "/";
    if (file_size(dir) != -2)
        return notify_fail(dir + "not exist。\n");
    log_file("loadall", "\n#check dir :" + dir);
    write("check dir " + dir + "\n");
    if (loadall(dir))
        return 1;
}

int loadall(string dir)
{
    string file, err, *dirs;

    if (!arrayp(get_dir(dir)))
        return 1;
    dirs = get_dir(dir);
    if (dir == "/")
        dirs = dirs - ({".git", ".vscode", "backup", "bin", "binaries", "cygdrive", "data", "dev", "doc", "dump", "grant", "help", "log", "proc", "temp", "u", "version"});

    // debug_message(sprintf("dirs = %O", dirs));
    foreach (file in dirs)
    {
        if (member_array(file, ({"u", "meskill"})) > -1)
            continue;

        reset_eval_cost();
        switch (file_size(dir + file))
        {
        case -1:
            //無法讀取該目錄，跳過
            break;
        case -2:
            if (file != "." && file != "..")
                call_out("loadall", 1, dir + file + "/");
            break;
        default:

            if ((dir + file)[ < 2.. < 1] == ".c")
            {
                if (err = catch (load_object(dir + file)))
                    log_file("loadall", "\n	check :" + dir + file + "\n" + err);
            }
        }
    }
    write("check dir " + dir + " is ok ^_^\n\n");
    return 1;
}

int help(object me)
{
    write(@HELP
    載入某個目錄下的所有.c文件(包含子目錄)，以查找所有
可能的編譯錯誤。

指令格式： loadall [dir]
比如      loadall /d/city/
沒有 dir，則dir默認爲 / ，文件太多可能會卡一會。

HELP );
    return 1;
}
