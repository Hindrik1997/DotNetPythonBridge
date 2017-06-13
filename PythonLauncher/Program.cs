using Microsoft.Scripting;
using Microsoft.Scripting.Hosting;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using IronPython.Hosting;
using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using ManagedLibrary;
using System.Threading;

namespace PythonLauncher
{
    class Program
    {
        [DllImport("kernel32.dll")]
        static extern IntPtr GetConsoleWindow();

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        private const int SW_HIDE = 0;
        private const int SW_SHOW = 5;

        private static bool caughtException = false;

        private static ScriptEngine m_Engine = Python.CreateEngine();

        static void Main(string[] args)
        {
            Console.WriteLine("Starting Python Module...");
            var handle = GetConsoleWindow();
            InitializePythonInterpreter();
            if (caughtException)
            {
                MessageBox.Show("An error occurred. Please read the Console to find out why!");
                return;
            }
            Console.WriteLine("All startup Python scripts succesfully completed!");
            ExposedInterface.RunLibrary();
        }

        public static void InitializePythonInterpreter()
        {
            Assembly thisAsm = Assembly.GetEntryAssembly();
            string path = Path.GetDirectoryName(thisAsm.Location);
            var paths = m_Engine.GetSearchPaths();
            paths.Add(path + "/Lib/");
            m_Engine.SetSearchPaths(paths);
            string[] Files = null;
            List<string> allowedExtensions = new List<string> { ".py" };
            try
            {
                Files = Directory.GetFiles((path + "/Python/"), "*.*", SearchOption.AllDirectories);
            }
            catch (Exception e)
            {
                MessageBox.Show("An exception occured when reading the python script directory. Does the Python directory exist?");
                Console.WriteLine(e.Message);
                caughtException = true;
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
                    caughtException = true;
                }
            }
        }


    }
}
