using System.Collections.Generic;

namespace ManagedLibrary
{
    public static class VariableStorage
    {
        
        private static Dictionary<string, string>   m_StringVals = new Dictionary<string, string>();

        private static Dictionary<string, int>      m_IntVals = new Dictionary<string, int>();

        private static Dictionary<string, double>   m_DoubleVals = new Dictionary<string, double>();

        private static Dictionary<string, byte[]> m_ByteArrayVals = new Dictionary<string, byte[]>();

        public static int GetInt(string name)
        {
            return m_IntVals[name];
        }

        public static void SetInt(string name, int value)
        {
            if (m_IntVals.ContainsKey(name))
            {
                m_IntVals[name] = value;
            }
            else
            {
                m_IntVals.Add(name, value);
            }
        }

        public static string GetString(string name)
        {
            return m_StringVals[name];
        }

        public static void SetString(string name, string value)
        {
            if (m_StringVals.ContainsKey(name))
            {
                m_StringVals[name] = value;
            }
            else
            {
                m_StringVals.Add(name, value);
            }
        }

        public static double GetDouble(string name)
        {
            return m_DoubleVals[name];
        }

        public static void SetDouble(string name, double value)
        {
            if (m_DoubleVals.ContainsKey(name))
            {
                m_DoubleVals[name] = value;
            }
            else
            {
                m_DoubleVals.Add(name, value);
            }
        }

        public static byte[] GetByteArray(string name)
        {
            return m_ByteArrayVals[name];
        }

        public static void SetByteArray(string name, byte[] value)
        {
            if (m_ByteArrayVals.ContainsKey(name))
            {
                m_ByteArrayVals[name] = value;
            }
            else
            {
                m_ByteArrayVals.Add(name, value);
            }
        }




    }
}
