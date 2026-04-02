// bug.c
inherit F_CLEAN_UP;
 
#include <ansi.h>
 

 
int main(object me, string arg)
{
        object ob;

        string sp/*, add*/;
        int bug/*, bugp */, flag;

        seteuid(getuid(me));

        if (! arg || !wizardp(me))
                ob = me;
        else
        if (wizardp(me) )
        {
                // 添加 bug 點數
                if (sscanf(arg, "%s %d", arg, bug) == 2)
                {
                        if (bug == 0)
 	                        return notify_fail("你到底是想添加還是"
                                                   "減少？\n");
                        if (! objectp(ob = find_player(arg)))
                                ob = LOGIN_D->find_body(arg);
                        if (! objectp(ob))
                        {
                            ob = new(USER_OB);
                            seteuid(arg);
                            export_uid(ob);
                            flag = 1;
                            if (!ob->restore())
                            {
                            	destruct(ob);
                            	return notify_fail("沒有這個玩家。\n");
                            }
                        }
                        ob->add("bug", bug);
                        ob->add("bug_count",bug);
                        ob->save();
                        sp = sprintf("用戶 " WHT "%s" NOR " 的報告點數"
                                     "增加了 " WHT "%d" NOR " 點，現爲"
                                     WHT " %d " NOR "點。\n", arg, bug,
                                     ob->query("bug", 1));

                        if (bug > 0)
                        tell_object(ob, HIG + me->name() + "增加了你的 " +
                                        bug + " 點報告點數。\n" NOR);
                        else 
                        tell_object(ob, HIG + me->name() + "減少了你的 " +
                                        -bug + " 點報告點數。\n" NOR);
                        

                        log_file("static/bug", sprintf("[%s] wizard %s a"
                                 "dd   %d bug point to user %s.\n",
                                 ctime(time()), getuid(me), bug, getuid(ob)));

                        //UPDATE_D->global_destruct_player(ob);

                        tell_object(me, sp);
                        if (flag == 1) destruct(ob);
                        return 1;
                }
                
                ob = present(arg, environment(me));
                if (! ob || ! ob->is_character()) ob = find_player(arg);
                if (! ob || ! ob->is_character()) ob = LOGIN_D->find_body(arg);
                if (! objectp(ob))
                {
                   ob = new(USER_OB);
                   seteuid(arg);
                   export_uid(ob);
                   flag = 1;
                   if (!ob->restore())
                   {
                    	destruct(ob);
                     	return notify_fail("沒有這個玩家。\n");
                    }
                 }
                if (base_name(ob)!=USER_OB)
                {
                	if (flag == 1) destruct(ob);
                    return notify_fail("只有玩家才具有此參數。\n");
                }
                        
        }
 
        bug = ob->query("bug", 1);

        if (! bug)
                sp = ((ob == me ? "你" : ob->name()) + "在" +
                         MUD_NAME + NOR "中尚無報告過任何錯誤。\n");
        else
                sp = ((ob == me ? "你" : ob->name()) + "在" +
                         MUD_NAME + NOR "中的錯誤報告積累點數爲"
                         HIC + bug +"/"+ob->query("bug_count")+ NOR "點。\n");

        tell_object(me, sp);
        if (flag == 1) destruct(ob);
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式： bugs
           bugs       <對象名稱>               (巫師專用)
           bugs       [<對象名稱> <點數>]      (巫師專用)

這個指令可以顯示你在遊戲中的錯誤報告積累點數。玩家可通過
此點數獲得一些獎勵。如果有巫師在線，可直接在公衆頻道彙報
錯誤，這時巫師可視 BUG大小給玩家增加報告點數。如遊戲中無
巫師在線，請用正式ID留言到巫師會客室或BUG留言室，我們會
在第一時間內修復 BUG及給此ID增加報告點數。（注意，只有匯
報 BUG的ID才能獲得點數。如果一個 BUG被數個玩家同時發現，
報告點數將加到最先彙報此 BUG的ID上。）

巫師可以使用添加或者減少玩家的報告點數。

細小錯誤：1點           (含錯別字、語句不通、幫助遺漏等)
一般錯誤：3點           (不會影響到遊戲正常進行的錯誤)
嚴重錯誤：5點           (視情況而論、包含某些系統錯誤)
練功錯誤：10至1000點    (有益於自身修煉及獲得利益的錯誤)

HELP);
        return 1;
}
