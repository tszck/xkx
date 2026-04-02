// recover cmds
// updated by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    mapping my;

    seteuid(getuid(me));

    if (!arg)
        ob = me;
    else
    {
        ob = present(arg, environment(me));
        if (!ob)
            ob = find_player(arg);
        if (!ob)
            ob = find_living(arg);
    }

    if (!ob)
        return notify_fail("你要恢復誰的狀態？\n");

    if (ob != me)
    {
        if (wiz_level(me) < wiz_level("(wizard)"))
            return notify_fail("你沒有權限恢復" + ob->name() + "。\n");
    }

    my = ob->query_entire_dbase();
    my["jing"] = my["eff_jing"] = my["max_jing"];
    my["jingli"] = my["eff_jingli"] = my["max_jingli"];
    my["qi"] = my["eff_qi"] = my["max_qi"];
    my["neili"] = my["max_neili"];
    my["food"] = ob->max_food_capacity();
    my["water"] = ob->max_water_capacity();

    if (me == ob)
    {
        message_vision(HIY "$N口中唸唸有詞，不一會兒就變得"
                           "精神煥發，神采奕奕。\n" NOR,
                       me);
        if (me->is_ghost())
            me->reincarnate();
        me->clear_condition();
    }
    else
    {
        message_vision(HIY "$N伸手一指，$n立刻精神煥"
                           "發，神采奕奕。\n" NOR,
                       me, ob);
        if (!living(ob))
            ob->revive();
        if (ob->is_ghost())
            ob->reincarnate();
        ob->clear_condition();
    }
    return 1;
}

int help()
{
    write(@HELP
指令格式 : full <對象名稱>

這個指令可以恢復你(你)或指定對象(含怪物)的精, 氣, 內力等數值。

HELP );
    return 1;
}
