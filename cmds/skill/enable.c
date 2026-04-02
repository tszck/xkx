// enable.c
inherit F_CLEAN_UP;

#include <ansi.h>


mapping valid_types = ([
        "array":        "陣法",
        "axe":          "斧法",
        "blade":        "刀法",
        "claw":         "爪法",
        "club" :        "棍法",
        "cuff":         "拳法",
        "dagger":       "短兵",
        "dodge":        "輕功",
        "finger":       "指法",
        "force":        "內功",
        "hammer":       "錘法",
        "hand":         "手法",
        "hook":         "鉤法",
        "leg":          "腿法",
        "magic":        "法術",
        "parry":        "招架",
        "spear":        "槍法",
        "staff":        "杖法",
        "stick":        "棒法",
        "strike":       "掌法",
        "sword":        "劍法",
        "throwing":     "暗器",
        "unarmed":      "拳腳",
        "whip":         "鞭法",
]);

int main(object me, string arg)
{
        mapping map;
        string /**types,*/ *skill, ski, map_to;
        int i, modify;

        seteuid(getuid());

        if( !arg ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("你現在沒有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是你目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等級：%s%3d\n" NOR,
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "無" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                return 1;
        }

        if( arg=="?" ) {
                write("以下是可以使用特殊技能的種類：\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }

        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("指令格式：enable|jifa [<技能種類> <技能名稱>|none]\n");

        if( undefinedp(valid_types[ski]) )
                return notify_fail("沒有這個技能種類，用 enable ? 可以查看有哪些種類。\n");

        if( map_to=="none" ) {
                me->map_skill(ski);
                me->reset_action();
write(HIY"你從現在起取消"HIG+CHINESE_D->chinese(ski)+HIY"的特殊技能。\n"NOR);
                return 1;
        } else if( map_to==ski ) {
                write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基礎，不需要 enable。\n");
                return 1;
        }

	if ( me->query_skill_prepared(ski) && me->query_skill_prepared(ski) != map_to)
		return notify_fail("這項技能你已經組合過了！\n");
        if( !me->query_skill(map_to, 1) )
                return notify_fail("你不會這種技能。\n");

//      if( !me->query_skill(ski, 1) )
//              return notify_fail("你連「" + to_chinese(ski) + "」都沒學會，
//              激發" + to_chinese(map_to) + "了。\n");

        if( !SKILL_D(map_to)->valid_enable(ski) )
                return notify_fail("這個技能不能當成這種用途。\n");

        me->map_skill(ski, map_to);
        me->reset_action();
write(HIY"你從現在起用"HIR+CHINESE_D->chinese(map_to)+HIY"作爲"HIG+CHINESE_D->chinese(ski)+HIY"的特殊技能。\n"NOR);

        if( ski=="magic" ) {
                write("你改用另一種法術系，精力必須重新鍛練。\n");
                me->set("jingli", 0);
                me->receive_damage("jing", 0);
        }
        else if( ski=="force" ) {
                write("你改用另一種內功，內力必須重新鍛練。\n");
                me->set("neili", 0);
                me->receive_damage("qi", 0);
//      } else if( ski=="spells" ) {
//              write("你改用另一種咒文系，法力必須重新修煉。\n");
//              me->set("mana", 0);
//              me->receive_damage("sen", 0);
        }

        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : enable|jifa [<技能種類> <技能名稱> | none]
           enable|jifa ?

    這個指令讓你指定所要用的技能，需指明技能種類和技能名稱。如果不
加參數則會顯示出技能種類及你目前所使用的技能名稱，如果加一個？會列
出所有能使用特殊技能的技能種類。

HELP
        );
        return 1;
}