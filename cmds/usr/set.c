// /cmds/usr/set.c

// Modified by Constant Jan 4 2001
inherit F_CLEAN_UP;
 
#define MAX_ENV_VARS	20
 


// 增加以下兩個數組，用於判斷環境變量設置的合法性。
// Added by Constant Jan 4 2001
string *player_settings = ({
	"brief",
	"brief1",
	"brief2",
	"combatd",
	"combatd2",
	"no_accept",
	"no_teach",
	"no_mail",
	"no_map",
	"no_tell",
	"prompt",
	"public",
	"verbose",
	"wimpy",
	"auto_regenerate",
	"halt_age",
	"no_fight",
	"can_tell",
	"auto_reply",
});

string *wizard_settings = ({
	"immortal",
	"invisibility",
	"msg_home",
	"msg_min",
	"msg_mout",
	"msg_clone",
	"msg_desg",
	"combat",
	"trace_error",
	"no_task_msg"
});
 

int help();
 
int main(object me, string arg)
{
	int i;
	string term, *terms;
	mixed data;
	mapping env;
 
	if ( me != this_player(1) ) 
		return 0;
 
	env = me->query("env");
 
	if ( !arg || arg=="" ) {
		write("你目前設定的環境變數有：\n");
		if ( !mapp(env) || !sizeof(env) )
			write("\t沒有設定任何環境變數。\n");
		else {
			terms = keys(env);
			for (i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	if ( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
 
	if ( term && term!="" ) {
		if ( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("你設的環境變量太多了，請先用 unset 刪掉幾個吧。\n");

		if ( member_array(term, player_settings) == -1 ) {
			if (!wizardp(me))
				return notify_fail("沒有這種環境變量，請參照幫助。\n");
			else if ( member_array(term, wizard_settings) == -1)
				return notify_fail("沒有這種環境變量，請參照幫助。\n");
		}
		if ((wiz_level(me) == 0) &&
			(member_array(term, wizard_settings) != -1))
			return notify_fail("只有巫師能用這個設定。\n");

		sscanf(data, "%d", data);
		me->set("env/" + term, data);
		printf("設定環境變數：%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <變量名> [<變量值>]
 
    這個指令讓你設定一些環境變量，不加參數時會顯示你目前設定
的環境變量，不指定變量值，則默認值爲 "YES"。這些變量會隨着你
的人物被儲存下來。
 
    取消變量設定請用 unset 指令。
 
    至於有哪些環境變量可以設定，請見 help setup。
TEXT
	);
	return 1;
}

