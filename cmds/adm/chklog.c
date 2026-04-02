inherit F_CLEAN_UP;

#define unusedvar_log_file "/log/var.log"

string file, *f_line, new_f_line, chk, unusedvar;
string wfile, *wf_line, lastw;
string filename, argv_name, c1, c2;
int start, line_n;
string *leixing = ({"int", "string", "object", "mapping", "mixed", "float", "buffer", "class", "array"});

int check(int s);
int check1();
int clean();
int isdata(string s); //對這一行簡單分析,判斷是否是數據定義行
int peidui(string s); //對這一行簡單分析,判斷([{}])是否殘缺

int main(object me, string arg)
{
    string *founded; //已經出現過的錯誤

    unusedvar = "";
    new_f_line = "";
    if (!arg)
        arg = "/log/log";
    if (file_size(arg) == -1)
    {
        write(arg + "文件不存在。\n");
        return 0;
    }
    if (!file = read_file(arg) || sizeof(file) == 0)
    {
        write("無法讀取該文件：" + arg + "\n");
        return 0;
    }

    f_line = explode(file, "\n");
    write_file(arg, "", 1);
    founded = ({});
    lastw = "";             //上一個錯誤文件名
    foreach (chk in f_line) //chk log file each line
    {
        if (sscanf(chk, "%s line %d: Warning: Unused local variable '%s'", filename, line_n, argv_name) == 3)
        {
            //  unusedvar+=chk+"\n";
            if (file_size(filename) == -1) //特別的update引起的檢查，一般不需要
            {
                write(filename + "文件不存在。\n");
                continue;
            }

            if (member_array(chk, founded) != -1)
                continue; //this mistake have be treated
            founded += ({chk});
            if (lastw != filename) //新文件有錯
            {
                if (lastw != "")
                {
                    write_file(lastw, implode(wf_line, "\n"), 1); //先保存修改老文件
                    unusedvar += "----write_file name==" + lastw + " end.....\n\n";
                }
                lastw = filename;
                unusedvar += chk + "\n";          ////
                if (!wfile = read_file(filename)) //再讀新文件
                {
                    write("無法讀取該文件：" + filename + "，可能是臨時文件\n");
                    continue;
                }
                wf_line = explode(wfile, "\n"); //wrong file lines

            } //否則接着修改剛才的文件，以免重複打開修改存盤同一文件
            unusedvar += "┏" + filename + " @line=" + line_n + ", Unused variable=" + argv_name + "\n";

            while (line_n > 0)
            {
                line_n--;
                //write("line_n ="+(line_n+1)+" \n it is "+wf_line[line_n] +"\n");

                if (isdata(wf_line[line_n]))
                { //write("line_n number=="+(line_n+1)+"    argv_name is "+argv_name +"\n");
                    start = 0;
                    if (check(start)) //找到並修改成功
                        break;
                }
            }
        } //  /d/dntg/sky/stars/23.c line 3: Cannot #include star.c before the end of file
        else if (sscanf(chk, "%s line %d: Cannot #include %s before", filename, line_n, argv_name) == 3)
        {
            if (member_array(chk, founded) != -1)
                continue; //this mistake have be treated
            founded += ({chk});
            if (lastw != filename) //新文件有錯
            {
                if (lastw != "")
                {
                    write_file(lastw, implode(wf_line, "\n"), 1); //先保存修改老文件
                    unusedvar += "----write_file name==" + lastw + " end.....\n\n";
                }
                lastw = filename;
                unusedvar += chk + "\n";
                if (!wfile = read_file(filename)) //再讀新文件
                {
                    write("無法讀取該文件：" + filename + "\n");
                    return 0;
                }
                wf_line = explode(wfile, "\n"); //wrong file lines

            } //否則接着修改剛才的文件，以免重複打開修改存盤同一文件
            unusedvar += "┏" + filename + " @line=" + line_n + ", Cannot #include=" + argv_name + "\n";

            while (line_n > 0)
            {
                line_n--;
                if (strsrch(wf_line[line_n], "<" + argv_name + ">") != -1)
                { //write("line_n number=="+(line_n+1)+"    argv_name is "+argv_name +"\n");
                    //start=0;
                    check1(); //找到並尋找文件嘗試修改
                    break;
                }
            }
        }
        else
            new_f_line = new_f_line + chk + "\n";
    }
    if (lastw != "")
        write_file(lastw, implode(wf_line, "\n"), 1);
    if (lastw != "")
        unusedvar += "-----------write file name==" + lastw + " end.....\n";
    else
        unusedvar += "\n-----------no file found Unused local variable or cannot be included file. end.....\n";
    write_file(unusedvar_log_file, unusedvar, 1);
    write_file(arg, new_f_line); //不認識的寫回原log文件
    write("ok.check " + unusedvar_log_file + " for examination。\n");
    return 1;
}

int isdata(string s) //對這一行簡單分析,判斷是否是數據定義行
{
    int n;
    foreach (chk in leixing)
    {
        if ((n = strsrch(s, chk)) != -1)
        {
            if (n != 0 && s[n - 1] != ' ' && s[n - 1] != '\t' && s[n - 1] != ';') // 類型名稱前面總得是空白吧
                return 0;
            n += sizeof(chk);
            if (s[n] == ' ' || s[n] == '*' || s[n] == '/' || s[n] == '\t') //有些定義數組是在類型後面加*，或某些變量已經註釋引起無法確定類型名稱
                return 1;
        }
    }
    return 0;
}

int check(int s) //對這一行詳細分析, 是否有未使用變量並修改
{
    int temp; //記錄變量字符串位置，符號配對性，防止有人開始定義變量時進行函數調用複雜的多變量初始化
    start = s;
    reset_eval_cost();
    if ((temp = strsrch(wf_line[line_n][s..], argv_name)) != -1) //檢查前後字符，看是否有這個變量
    {
        start += temp; //開始位置
        c1 = wf_line[line_n][start - 1..start - 1];
        //write("111argv_name is "+argv_name +" c1 is "+c1+"\n");
        if (member_array(c1, ({" ", ",", "*", "/", "\t"})) == -1)
            return check(start + sizeof(argv_name)); //前面不是空格或逗號或星號，應該不是變量，檢查後面可能有這個變量
        //write("111\n");
        c2 = wf_line[line_n][start + sizeof(argv_name)..start + sizeof(argv_name)];
        if (member_array(c2, ({" ", ",", ";", "=", "/", "\t"})) == -1) //後面不是空格或逗號或分號，應該不是變量，檢查後面可能有這個變量
            return check(start + sizeof(argv_name));
        while (member_array(c1, ({" ", ",", "*", "/", "\t"})) != -1) //把左邊沒有用的這些當成變量的一部分，呆會一起註釋掉
        {                                                            //write("left argv_name is "+argv_name +" c1 is "+c1+"\n");
            if (c1 == "/")
                break;
            argv_name = c1 + argv_name;
            start--;
            c1 = wf_line[line_n][start - 1..start - 1];
        }
        while (1)
        {
            if (peidui(argv_name) == 1)
            {                                            //write("right argv_name is "+argv_name +" c2 is "+c2+"\n");
                if (c2 == ";" || c2 == "/" || c2 == ",") //一定要結束
                {
                    if (strsrch(argv_name, ",") == -1) //變量左邊沒有逗號，説明是第一個變量，需要消除後面的，
                        if (c2 == ",")
                            argv_name = argv_name + c2;
                    break;
                }
            }
            argv_name = argv_name + c2;
            c2 = wf_line[line_n][start + sizeof(argv_name)..start + sizeof(argv_name)];
        }
        if (argv_name[0..1] == "* " || argv_name[0..1] == "*\t")
            argv_name = argv_name[1..]; //防止有人把*寫在類型後面的習慣
        if (argv_name[0..0] == " " || argv_name[0..0] == "\t")
            argv_name = argv_name[1..]; //防止已有的註釋把/*寫在類型後面,導致無法識別類型
        unusedvar += "┣the wrong is " + "@line" + (line_n + 1) + "【" + wf_line[line_n] + "】\n";
        //wf_line[line_n]=wf_line[line_n][0..start-1]+replace_string(wf_line[line_n][start..],argv_name,"/*"+argv_name+"*/",1);//註釋掉變量
        wf_line[line_n] = wf_line[line_n][0..start - 1] + replace_string(wf_line[line_n][start..], argv_name, "", 1); //註釋掉變量

        clean();
        return 1;
    }

    return 0;
}

int check1() //檢查同目錄下、include/net/下是否有這個include文件
{
    string dir;
    dir = filename[0..strsrch(filename, "/", -1)];
    reset_eval_cost();
    if (member_array(argv_name, get_dir(dir)) == -1) //當前目錄下沒有這個文件
        unusedvar += "┣the wrong is " + "@line" + (line_n + 1) + "『" + wf_line[line_n] + "』,cannot find the " + argv_name + " in the same dir.\n";
    else //當前目錄下有這個文件
    {
        unusedvar += "┣the wrong is " + "@line" + (line_n + 1) + "【" + wf_line[line_n] + "】\n";
        wf_line[line_n] = replace_string(wf_line[line_n], "<" + argv_name + ">", "\"" + argv_name + "\"", 1); //改為include 本目錄下文件
        unusedvar += "┗the corrected line" + (line_n + 1) + "〖" + wf_line[line_n] + "〗\n";
        return 1;
    }

    if (member_array(argv_name, get_dir("include/net/")) == -1) //include/net目錄下沒有這個文件
        unusedvar += "┣the wrong is " + "@line" + (line_n + 1) + "『" + wf_line[line_n] + "』,cannot find the " + argv_name + " in the include/net\n";
    else //include/net目錄下有這個文件
    {
        unusedvar += "┣the wrong is " + "@line" + (line_n + 1) + "【" + wf_line[line_n] + "】\n";
        wf_line[line_n] = replace_string(wf_line[line_n], argv_name, "net/" + argv_name, 1); //改為include/net 目錄下文件
        unusedvar += "┗the corrected line" + (line_n + 1) + "〖" + wf_line[line_n] + "〗\n";
    }
    return 1;
}

int clean() //clean class name alone
{
    string class_lonely;
    wf_line[line_n] = replace_string(wf_line[line_n], "\t", " ");

    //可能有多個不同定義在一行裏 int a; string b ; object c; //xxxxx
    //可能已經註釋了a 、b、c，需要清理掉類型名
    while (strsrch(wf_line[line_n], " ;") > 0)
        wf_line[line_n] = replace_string(wf_line[line_n], " ;", ";");
    foreach (class_lonely in leixing)
    {
        wf_line[line_n] = replace_string(wf_line[line_n], class_lonely + ";", "");
        wf_line[line_n] = replace_string(wf_line[line_n], class_lonely + "*;", "");
    }

    unusedvar += "┗the corrected line" + (line_n + 1) + "〖" + wf_line[line_n] + "〗\n";
}

int peidui(string arg) //from nt7,對這一行簡單分析,判斷([{}])是否殘缺
{
    int idx, chr, mark, marked;
    int s_symbol, m_symbol, b_symbol, d_quote, s_quote;
    idx = 0;
    chr = 0;
    mark = 0;
    marked = 0;
    s_symbol = 0;
    m_symbol = 0;
    b_symbol = 0;
    d_quote = 0;
    s_quote = 0;
    for (idx = 0; idx < strlen(arg); idx++)
    {
        chr = arg[idx];
        mark = (chr == '\\');
        if (mark)
            marked++;
        if (!(s_quote % 2) && (!marked || !(marked % 2)) && chr == '\"')
            d_quote++;
        if (!(d_quote % 2) && (!marked || !(marked % 2)) && chr == '\'')
            s_quote++;
        if (!mark)
            marked = 0;
        if (d_quote % 2)
            continue;
        switch (chr)
        {
        case '(':
            s_symbol++;
            break;
        case ')':
            s_symbol--;
            break;
        case '[':
            m_symbol++;
            break;
        case ']':
            m_symbol--;
            break;
        case '{':
            b_symbol++;
            break;
        case '}':
            b_symbol--;
            break;
        }
    }

    if (d_quote % 2 || s_quote % 2 || s_symbol || m_symbol || b_symbol)
        return 0;
    return 1;
}

int help(object me)
{
    write(@HELP
    自動註釋掉源文件中所有mudos或fluffos發現的未使用的變量，
修改 #include <本目錄下文件>  為  #include "本目錄下文件";
以節約內存，註釋後的文件記錄會從log文件中刪除，以減小log文
件，其它不認識的錯誤會寫回原log文件.以方便巫師查錯。
    已經註釋的文件另給一個記錄，默認文件名為/log/log.var
前面是log文件本身，後面是修改情況正常情況開始會形成三行封閉
的製表符，以方便判斷是否註釋正確。
    若代碼不能正確處理，請在各個wiz羣聯繫胖得爬不上樹的精靈
雖然我可能也忘了代碼。

指令格式：chklog [logfile]
沒有 logfile，則logfile默認為 log/log
HELP
    );
    return 1;
}
