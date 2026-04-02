// shop.c

inherit F_CLEAN_UP;

#include <ansi.h>

int help(object me);

int main(object me, string arg)
{
        string name, id;
	seteuid(getuid());
        if (! arg)
        {
                SHOP_D->list_shop(me);
                return 1;
        }
        if (! wizardp(me))
                return notify_fail("你沒有權力使用店鋪管理指令。\n");

        switch (arg)
        {
        case "all"   : SHOP_D->do_listall(me); break;
        case "open"  : SHOP_D->open_all(me); break;
        case "close" : SHOP_D->close_all(me); break;
        case "reset" : SHOP_D->reset_all(me); break;
        default :
                if (sscanf(arg, "open %s", name))
                {
                        SHOP_D->open_shop(me, name);
                        break;
                }
                if (sscanf(arg, "close %s", name))
                {
                        SHOP_D->close_shop(me, name);
                        break;
                }
                if (sscanf(arg, "reset %s", name))
                {
                        SHOP_D->reset_shop(me, name);
                        break;
                }
                if (sscanf(arg, "owner %s %s", name, id))
                {
                        SHOP_D->change_owner(me, name, id);
                        break;
                }
                else return help(me);
        }
        
        return 1;
}

int help (object me)
{
	write(@HELP

指令格式：shop [ open [店鋪名稱] ]  | [ close [店鋪名稱] ] |
               [ reset [店鋪名稱] ] | [ owner <店鋪名稱> <店主ID> ]
               [ all ]

玩家查看當前遊戲中的店鋪經營狀況。

巫師可以用於管理店鋪：
使用 open 參數開放指定的一個店鋪或者所有店鋪。
使用 close 參數將關閉指定的一個店鋪或者所有店鋪。
使用 reset 參數重新初始化指定的一個店鋪或者所有店鋪。
而使用owner 參數則是設置店主的 id。
使用 all 則顯示所有商店貨物。

HELP);
        return 1;
}


