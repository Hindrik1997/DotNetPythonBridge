using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Drawing;
using System.Reflection;
using System.ComponentModel;
using System.IO;
using Microsoft.Scripting;
using Microsoft.Scripting.Hosting;
using IronPython.Hosting;

namespace ManagedLibrary
{
    public static class ExposedInterface
    {

        public static MainForm m_Form = new MainForm();
        private static ScriptEngine m_Engine = Python.CreateEngine();

        public static void RunLibrary()
        {
            InitializePythonInterpreter();
            Application.Run(m_Form);
        }

        public static Button CreateNewButton(int width, int height, int x, int y, string text)
        {
            Button b = new Button();

            b.Size = new Size(width, height);
            b.Location = new Point(x, y);
            b.Text = text;

            m_Form.AttachControl(b);
                        
            return b;
        }

        public static TextBox CreateNewTextBox(int width, int height, int x, int y, string text)
        {
            TextBox b = new TextBox();

            b.Size = new Size(width, height);
            b.Location = new Point(x, y);
            b.Text = text;

            m_Form.AttachControl(b);

            return b;
        }

        public static void SetEventHandler(Button button, string PythonFile)
        {
            RemoveClickEvent(button);

            button.Click += new EventHandler(delegate (object sender, EventArgs e) {

                RunEventHandler(PythonFile);

            });
        }


        private static void RemoveClickEvent(Button b)
        {
            FieldInfo f1 = typeof(Control).GetField("EventClick", BindingFlags.Static | BindingFlags.NonPublic);
            object obj = f1.GetValue(b);
            PropertyInfo pi = b.GetType().GetProperty("Events", BindingFlags.NonPublic | BindingFlags.Instance);
            EventHandlerList list = (EventHandlerList)pi.GetValue(b, null);
            list.RemoveHandler(obj, list[obj]);
        }

        private static void InitializePythonInterpreter()
        {
            Assembly thisAsm = Assembly.GetEntryAssembly();
            string path = Path.GetDirectoryName(thisAsm.Location);
            var paths = m_Engine.GetSearchPaths();
            paths.Add(path + "/Lib/");
            paths.Add(path + "/Libraries/");
            m_Engine.SetSearchPaths(paths);
        }

        private static void RunEventHandler(String file)
        {
            Assembly thisAsm = Assembly.GetEntryAssembly();
            string path = Path.GetDirectoryName(thisAsm.Location);
            string[] Files = null;
            List<string> allowedExtensions = new List<string> { ".py" };
            try
            {
                Files = Directory.GetFiles((path + "/Event Handlers/"), "*.*", SearchOption.AllDirectories);
            }
            catch (Exception e)
            {
                MessageBox.Show("An exception occured when reading the python eventhandler script directory. Does the Python directory exist?");
                Console.WriteLine(e.Message);
                return;
            }
            List<string> PythonFiles = new List<string>();
            foreach (string s in Files)
            {
                string t = Path.GetExtension(s);
                if (allowedExtensions.Contains(t))
                {
                    PythonFiles.Add(s);
                }
            }



            foreach (string f in PythonFiles)
            {
                String t2 = Path.GetFileNameWithoutExtension(f);
                if (t2 != file)
                    continue;

                string sourceCode = File.ReadAllText(f);
                var ScriptSource = m_Engine.CreateScriptSourceFromString(sourceCode, SourceCodeKind.AutoDetect);
                try
                {
                    ScriptSource.Execute();
                }
                catch (Exception e)
                {
                    ExceptionOperations eo = m_Engine.GetService<ExceptionOperations>();
                    string error = eo.FormatException(e);
                    Console.WriteLine(error);
                }
                return;
            }
            Console.WriteLine("No Eventhandler found!");
        }
    }

}
