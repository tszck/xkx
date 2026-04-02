// /cmds/usr/unset.c

// Modified by Constant Jan 4 2001

inherit F_CLEAN_UP;

// 增加以下兩個數組，用於檢查環境變量設置的合法性。
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
	"trace_error"
	"no_task_msg"
});

int help();

int main(object me, string arg)
{
	if (!arg || arg=="") 
		return help();

	if (arg == "all") { 
		me->delete("env");
		write("你的環境變量已被清空。\n");
		return 1;
	}

	if (!me->query("env/" + arg))
		return notify_fail("你並沒有設過這個環境變量。\n");

	if (member_array(arg, player_settings) == -1) {
		if (!wizardp(me))
			return notify_fail("沒有這種環境變量，請參照幫助。\n");
		else if (member_array(arg, wizard_settings) == -1)
			return notify_fail("沒有這種環境變量，請參照幫助。\n");
	}

	me->delete("env/" + arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：unset <變量名> | all

    這個指令讓你刪除環境變量的設定，若所帶參數為all， 則刪
除所有環境變量。

See also：set
TEXT
	);
	return 1;
}

