// 測試專用
int main(object me, string arg)
{
    /* clean up first */

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP

測試專用，請先實現功能後運行。

HELP);

    return 1;
}
