#pragma once

#include <Windows.h>
#include <comdef.h>


////////////////////////////////////////////////////////////////
//                     ö��


enum DismPackageState
{
	DismPackageStateUnknown = 0,
	DismPackageStateNotPresent,
	DismPackageStateUnintallRequested,
	DismPackageStateStaged,              //�ݴ�
	DismPackageStateStaging,             //�����ݴ�
	DismPackageStateInstalled,           //�����Ѿ���װ
	DismPackageStateInstallRequested,    //��װ����
	DismPackageStateSuperseded,          //�ø����Ѿ���ȡ��
	DismPackageStatePartiallInstalled,   //���ְ�װ
	DismPackageStateRemoved,             //�Ѿ�ɾ��
	DismPackageStatePermanent,           //���ù̻����°�
};
enum DismFeatureState
{
	DismFeatureStateUnknown = 0,
	DismFeatureStateNotPresent,
	DismFeatureStateUnintallRequested,   //�ù����Ѿ��رյ���δ��Ч
	DismFeatureStateDisable,             //�ù����Ѿ��ر�
	DismFeatureStateStaging,
	DismFeatureStateEnable,              //�ù��ܱ�����
	DismFeatureStateEnableRequested,     //�ù����Ѿ�����������δ��Ч
	DismFeatureStateSuperseded,          //�ù����Ѿ���ȡ��
	DismFeatureStatePartiallInstalled,   //�ù��ܲ��ְ�װ
	DismFeatureStateRemoved              //�ù����Ѿ�ɾ��
};

enum DismFullyOfflineInstallableState
{
	DismPackageFullyOfflineUnknow = 0,
	DismPackageFullyOfflineInatallable,
	DismPackageFullyOfflineNotInatallable,
};



enum DismDriverSinStatus
{
	DismDriverSinStatusUnknow = 0,
	DismDriverSinStatusUnsigned,
	DismDriverSinStatusSinged
};


enum DriverShowEnum
{
	DriverShowAll = 0,
	DriverShowInbox = 1,
	DriverShowOutOfBox = 2
};


enum DismMountedImageStatus
{
	DismMountedImageStatusValid = 0,
	DismMountedImageStatusMounting = 1,
	DismMountedImageStatusInvalid = 2,
	DismMountedImageStatusNeedsRemount = 4
};

enum DismImageFileTpye
{
	WimImageFile,
	VhdImageFile
};

//WIM����esd�ļ���ѹ������
enum DismCompressTpye
{
	//δ֪ѹ������
	Compress_Unknown = -1,

	//���洢����ѹ���ļ�
	Compress_None = 0,

	//��ѹ����ʽ֧��WIMBOOT����
	Compress_XpressHuffman = 1,

	//����ѹ�������Խ�ʡѹ��ʱ�䲢�ҿ��Լ����ύռ��
	Compress_Xpress = 2,

	//���ѹ�������Խ�ʡ�ռ�
	Compress_LZX = 3,

	//����ѹ�����ǳ��ķ�ʱ�䣬���������С
	Compress_LZMS = 4,
};


enum DismServiceStartType
{
	//��������δ֪��������ϵͳ�����Ҳ������Dism�޷�ʶ��������������ͣ�Ϊ�˰�ȫ��Dism++�޷��޸���������δ֪����Ŀ
	DismServiceStartTypeUnknown = -1,
	//�÷����Ѿ��ر�
	DismServiceStartTypeDisable,
	//�÷���Ϊ�ֶ�����
	DismServiceStartTypeManual,
	//�÷������Զ�����
	DismServiceStartTypeAuto,
	//�÷������ӳ�������ע����_�����ӳٱ�ǵ��޷��޸�Ϊ�ӳ��������᷵�ز�������
	DismServiceStartTypeDelayed
};

enum DismSystemStatus
{
	//״̬δ֪
	DismSystemStatusUnknown = -1,
	//׼������
	DismSystemStatusReady,
	//��ϵͳ��֧��Dism++
	DismSystemStatusNotSupported,
	//�Ҳ���ϵͳ��Ŀ��Ŀ¼�޷����ʻ���·��������
	DismSystemStatusCannotFind,
	//�����Ѿ�ʧЧ����Ҫɾ��
	DismSystemStatusNeedRemove,
	//���Ե�
	DismSystemStatusWait
};


enum DismEnvironmentType
{
	DismEnvironmentDefault = 0, //32λϵͳ���32λĿ¼��64λϵͳ��ȡ64λ·��
	DismEnvironment64Only,    //������ȡ64λ·��������32λϵͳ��ʧ�ܣ�
	DismEnvironment86Only,    //���Ƿ���32λ·��
};


enum DismImageHealthState
{
	DismImageHealthy = 0,      //ӳ��ʮ�ֽ�������Ҫ�޸�
	DismImageRepairable = 1,   //ӳ���Ѿ����𣬵��ǿ����޸�
	DismImageNonRepairable = 2 //ӳ���Ѿ��յ��������⣬�����޸�
};

enum DismServiceType
{
	DismSystemService,    //ϵͳ����
	DismAppService,       //������Ӧ�ó���
	DismDriverService,    //��������
};


enum ProfileStatus
{
	ProfileStatusDisabled = 0,
	ProfileStatusEnabled = 1,
	ProfileStatusApplied = 2,
	ProfileStatusMax
};

enum StartupType
{
	StartupTypeUnknow = -1,

	//HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
	StartupTypeSystemRun,

	//HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\Run
	StartupTypeSystemRun32,

	//HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce
	StartupTypeSystemRunOnce,

	//HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\RunOnce
	StartupTypeSystemRunOnce32,

	//HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
	StartupTypeUserRun,

	//HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce
	StartupTypeUserRunOnce,

	//%SystemDirve%\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup
	StartupTypeAllUsersStartupFolder,

	//%UserProfile%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
	StartupTypeCurrentUserStartupFolder,

	//HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager
	StartupTypeNativeBootExecute,

	//HKEY_USERS\DEFAULT\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
	StartupTypeDefaultUserRun,

	//HKEY_USERS\DEFAULT\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce
	StartupTypeDefaultUserRunOnce,
};

enum StartupState
{
	StartupStateRemove = -1,
	StartupStateDisable,
	StartupStateEnable,
};

////////////////////////////////////////////////////////////////
//                      �ṹ����

#pragma pack(push, 1)

struct DismSystem
{
	//ϵͳ״̬
	DismSystemStatus Status;

	/*
	����ϵͳCPU��ϵ������ֵΪ��
	PROCESSOR_ARCHITECTURE_AMD64     x64��ϵ
	PROCESSOR_ARCHITECTURE_INTEL     x86��ϵ
	PROCESSOR_ARCHITECTURE_UNKNOWN   δ֪��ϵ*/
	long Architecture;

	//����ָʾ
#define _����ӳ��      0x1     //���Ϊ����ӳ����ô�ñ��Ϊ1 ����Ϊ0

	//������ʽ
#define _����Ӳ��      0x2  //ӳ�����ڱ���
#define _����ӳ��      0x4  //ӳ��������WIM����VHD���ص�

	//ʹ�õļ���
#define _WIMBOOT       0x8  //ӳ��ʹ����WIMBOOT����
#define _VHDװ��       0x10  //ӳ������VHDװ��
#define _CompactOs     0x20  //ӳ��ʹ����CompactOs����
#define _WinPE         0x40
	//�û��Զ����� 24~31  Dism++API���Ա�֤����ʹ����������������������µĶ���
	DWORD Flags;       //Flagsӵ��������ϱ�־
	DWORD ProductType;          //��Ȩ���� WinNT��LanmanNT ���� ServerNT

	//ϵͳ�汾�� ����6.3.9600.17041
	UINT16 Version[4];


	wchar_t ProductName[256];    //����ϵͳ����
	wchar_t EditionID[256];      //ϵͳ����汾

	wchar_t InstallationType[40];      //ϵͳ��װ����
	DWORD DefaultLanguage;      //Ĭ����ʾ����
	DWORD InstallLanguage;      //ϵͳ��װ����
	wchar_t InstallLanguageFallback[256];//���Ի����б�
	//WIM XML�е�Flags
	wchar_t szFlags[256];
	wchar_t RootPath[MAX_PATH];       //ϵͳ��װλ��
	//ӳ����չ·�������ڱ���WIM·���Լ�VHD·�� ���ַ��ַ���
	wchar_t ExtendPath[1];
};


struct DismPackage
{
	DismPackageState State;
	wchar_t RestartRequired[40];

	wchar_t ReleaseType[40];
	wchar_t Identity[256];
	wchar_t Name[256];
	wchar_t Description[512];
	wchar_t ProductName[256];
	wchar_t ProductVersion[256];
	wchar_t Company[256];
	wchar_t Copyright[256];
	wchar_t SupportInformation[512];
	wchar_t InstallPackageName[256];
	wchar_t InstallLocation[256];
	wchar_t InstallClient[256];
	wchar_t InstallUserName[256];

	//����
	FILETIME CreationTime;
	FILETIME LastUpdateTime;
	FILETIME InstallTime;

	wchar_t FullyOfflineInstallable[256];
	wchar_t ScavengeSequence[40];

	VARIANT_BOOL IsApplicable;
};

struct DismFeature
{
	DismFeatureState State;
	wchar_t RestartRequired[40];
	wchar_t Name[256];
	wchar_t DisplayName[512];
	wchar_t Description[512];
	//DWORD ParentFeatureNameCount;
	wchar_t ParentFeatureName[40];
};

struct DismCapability
{
	DismFeatureState State;
	DWORD DownloadSize;
	DWORD InstallSize;

	wchar_t Name[256];
	wchar_t ID[256];
	wchar_t DisplayName[512];
	wchar_t Description[512];
};


struct DismDriver
{
	wchar_t LocaleName[0x55];
	wchar_t InfProviderName[0x104];
	wchar_t CatalogFile[0x104];
	wchar_t InfPath[0x104];
	wchar_t PublishedInfName[256];
	GUID ClassGuid;
	wchar_t ClassName[0x104];
	wchar_t ClassDescription[256];
	UINT16 Version[4];
	FILETIME Date;
	VARIANT_BOOL InBox;
	VARIANT_BOOL BootCritical;
	VARIANT_BOOL SigStatus;
};


struct DismMountedImage
{
	wchar_t MountDir[MAX_PATH];
	wchar_t ImagePath[MAX_PATH];
	DWORD Index;
	DismMountedImageStatus Status;
	VARIANT_BOOL ReadWritable;
};

struct DismImageInfo
{
	//ϵͳ��ϵ
	long Architecture;

	//��������
	FILETIME CreationTime;

	//չ���ռ�
	UINT64 Space;

	//ϵͳ�汾��
	UINT16 Version[4];

	//////////////////////////////////////////////////
	//        ������޸�������Ϣ ������ӳ����Ϣ

	//ӳ������
	wchar_t Name[256];

	//ӳ��˵��
	wchar_t Description[512];

	//��ʾ����
	wchar_t DisplayName[256];

	//��ʾ˵��
	wchar_t DisplayDescription[512];

	//ӳ��汾���
	wchar_t Flags[256];
};

struct DismImageFileInfo
{
	//�����±�
	int BootIndex;

	//�ļ�����
	DismImageFileTpye Type;

	//�ļ�Ψһ��ʶ
	GUID FileGUID;

	//ѹ������
	DismCompressTpye Compression;

	//ӳ������
	DWORD ImageInfoCount;

	//ӳ��
	DismImageInfo ImageInfo[0];
};

struct DismService
{
	DismServiceType Type;
	/*
	������������,����ֵΪ
	SERVICE_AUTO_START
	SERVICE_BOOT_START
	SERVICE_DEMAND_START
	SERVICE_DISABLED
	SERVICE_SYSTEM_START
	*/
	//�ӳ�����
#define SERVICE_Delay_START 5
	DWORD dwStartType;

#define _ϵͳ���� 0x00000001
#define _�����ӳ� 0x00000002
#define _ϵͳ���� 0x00000004
	//����Flags ӵ������״̬
	DWORD Flags;

	//��������
	wchar_t Name[256];

	//��Ӧ������ʾ����
	wchar_t DisplayName[256];

	//��Ӧ������ʾ����
	wchar_t Description[512];

	//��Ӧ����·��
	wchar_t ImagePath[MAX_PATH];

	//��Ӧ����ĵ�¼״̬
	wchar_t ObjectName[256];
};


struct AppxPackage
{
	//��ǰ�ṹ���С��ָ����һ��AppxPackageԪ��
	DWORD cbData;
	wchar_t FullName[256];
	wchar_t InstalledLocation[MAX_PATH];
	wchar_t Users[1];
};



#pragma pack(pop)



typedef class CCbsHostProxy* DismSession;


#define DISM_MSG_PROGRESS   38008     //������ϢwParamΪ��ǰ��ɰٷֱ�
#define DISM_MSG_PROCESS    38009     //ָʾ���ļ��Ƿ�Ӧ�ñ�����wParam = (PWSTR) pszFullPath   lParam = (PBOOL) pfProcessFile
#define DISM_MSG_SCANNING   38010     //ɨ����ļ��������ļ��� wParam=(BOOL)IsDirector   lParam=(UINT)Count
#define DISM_MGS_RemoveInfo 37001     //ָʾ���ļ������ļ�����Ҫ����   wParam=(DWORD)Type    lParam=(LPCWSTR)FilePath
#define Dism_MSG_QUERY_ABORT 38030    //�Ƿ���Ҫ�жϸò���������-1 ���жϵ�ǰ����������S_OK��ô������������ 

//Dism�ص����������ڷ��ؽ��ȵ���ϢdwMessageId�������ϼ�����Ϣ  UserData���㴫���ָ�� ��������������У��뷵�� ERROR_SUCCESS
typedef DWORD(WINAPI *DismCallBack)(DWORD dwMessageId, WPARAM wParam, LPARAM lParam, PVOID UserData);


///////////////////////////////////////////////��������֧��////////////////////////////////////////////////
//
//

//��ȡָ����ע����ֵ,���ú���Ҫʹ��RegClose�ر�
HRESULT WINAPI DismRegOpenKeyEx(DismSession Session, HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, PHKEY phkResult);

//������ֵ
HRESULT WINAPI DismRegCreateKeyEx(DismSession Session, HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, PHKEY phkResult, LPDWORD lpdwDisposition);

//��ȡָ����ע����ֵ,���ú���Ҫʹ��RegClose�ر�
HRESULT WINAPI DismRegOpenKey(DismSession Session, HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);

//ת��ָ���Ļ�������
HRESULT WINAPI DismExpandEnvironmentStrings(DismSession Session, LPCWSTR lpSrc, LPBSTR lpDst);

#define DismLogLevelSilent      0    //������κ���Ϣ
#define DismLogLevelFailure     1    //������
#define DismLogLevelWarning     2    //����;���
#define DismLogLevelInformation 3    //���󡢾������Ϣ
#define DismLogLevelDebug       4    //�����������ݺ͵������
//д����־
HRESULT WINAPI DismWriteLog(DWORD LogLevel, LPCWSTR LogName, LPCWSTR LogValue);

//�ͷ�Dism�ӿڵ��ú�Ŀռ�
HRESULT WINAPI DismFreeMemory(void* pStruct);

//���ݻỰ���ϵͳ��Ϣ
HRESULT WINAPI DismGetSystemInfoBySession(DismSession Session, DismSystem** Info);

//����·�����ϵͳ��Ϣ
HRESULT WINAPI DismGetSystemInfoByPath(LPCWSTR RootPath, DismSystem** Info);

//��ָ���������ת��Ϊ��Ӧ�ı���
HRESULT WINAPI DismFormatMessage(HRESULT hr, LPBSTR ppErrorMessage);

//��ȡ��ʱĿ¼
LPCWSTR WINAPI DismGetScratchDir();

BOOL WINAPI DismUnloadRegMount(LPCWSTR RootPath);

//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////���°�����///////////////////////////////////////////////
//
//

//��Ӹ��°�
HRESULT WINAPI DismAddPackage(DismSession Session, LPCWSTR PackageFilePath, DismCallBack CallBack, LPVOID UserData);

//ɾ�����°�
HRESULT WINAPI DismRemovePackage(DismSession Session, LPCWSTR PackageName, DismCallBack CallBack, LPVOID UserData);

//��ȡ���°���Ϣ
//HRESULT WINAPI DismGetPackage(DismSession Session, LPCWSTR PackageIdentity, DismPackage** ppPackageInfo);

//��ȡ���и��°�
HRESULT WINAPI DismGetPackages(DismSession Session, DismPackage** ppPackages, DWORD* pCount, DismCallBack CallBack, LPVOID UserData);

//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////���ܰ�����/////////////////////////////////////////////////////
//

HRESULT WINAPI DismChangeFeatures(DismSession Session,
	LPCWSTR FeatureNames,  //��Ҫ�رյĹ�������
#define DismLimitAccess 0x00000001   //NT6.1��Ч �򿪹���ʱ��Ҫ��΢��������������ļ� PS����������趨���ܻ�Ӧ�ò������ص��ļ�����ʧ��
	DWORD ChangeFlags,   //�رձ�־��֧������״̬
	LPCWSTR SourcePaths,  //NT6.1��Ч ָ������Դ������������ʱ���ȴ�Դ�����ļ�,���Դ��NULL�ָ�
	DismCallBack CallBack, LPVOID UserData);

//��ȡ����״̬
HRESULT WINAPI DismGetFeatures(DismSession Session, DismFeature** ppFeature, LPDWORD pCount, DismCallBack CallBack, LPVOID UserData);

//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////ϵͳ�޸�����///////////////////////////////////////////////////////
//
//

//ɨ��ϵͳ�Ƿ�����
HRESULT WINAPI DismScanHealth(DismSession Session, DismImageHealthState* pImageHealthState, DismCallBack CallBack, PVOID UserData);

//�ָ�ϵͳ����
HRESULT WINAPI DismRestoreHealth(DismSession Session, LPCWSTR SourcePaths, DismCallBack CallBack, PVOID UserData);

//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////��ѡ����///////////////////////////////////////////////////////
//
//
//���ӱ��ػ�ȡ
#define CapabilityFlagsPackageStore 0x1
//�Ӱ�װԴ�л�ȡ
#define CapabilityFlagsLocalSouce   0x2
//���ƶ˻�ȡ
#define CapabilityFlagsCloud        0x4

//��ȡ���п�ѡ����״̬
HRESULT WINAPI DismGetCapabilities(DismSession Session, DWORD CapabilityFlags, DismCapability** ppCapabilitites, DWORD* pCount);

//ɾ����ѡ����
HRESULT WINAPI DismRemoveCapability(DismSession Session, LPCWSTR CapabilityName, DismCallBack CallBack, LPVOID UserData);

//��ӿ�ѡ����
HRESULT WINAPI DismAddCapability(DismSession Session, LPCWSTR CapabilityName, DismCallBack CallBack, LPVOID UserData);
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////��������֧��//////////////////////////////////////////////////////
//
//

//��ȡ���з���
HRESULT WINAPI DismGetServices(DismSession Session, DismService** ppService, DWORD *pCount, DismCallBack CallBack, LPVOID pUserData);

//ɾ������
HRESULT WINAPI DismRemoveService(DismSession Session, LPCWSTR Name);

//�޸ķ�����������
HRESULT WINAPI DismSetServiceStart(DismSession Session, LPCWSTR Name, DWORD StartType);

//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////����������//////////////////////////////////////////////////////
//
//

//���������
HRESULT WINAPI DismAddDriver(DismSession Session, LPCWSTR DriverPath);

//ɾ��������
HRESULT WINAPI DismRemoveDriver(DismSession Session, LPCWSTR DriverName);

//��ȡ����������
HRESULT WINAPI DismGetDrivers(DismSession Session, DismDriver** ppDrivers, DWORD* pCount, DriverShowEnum DriverShow, DismCallBack CallBack, LPVOID UserData);

//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////�������////////////////////////////////////////////////////////
//
//

//������ڲ���Ҫ�ĸ���
HRESULT WINAPI DismComponentCleanup(DismSession Session, DWORD Reserved, UINT64 *CleanUpSpace, DismCallBack CallBack, LPVOID UserData);

//��������Լ���ʹ�õ�����
HRESULT WINAPI DismDriverCleanup(DismSession Session, DWORD Reserved, UINT64 *CleanUpSpace, DismCallBack CallBack, LPVOID UserData);

//������Ҫ��Metro App
HRESULT WINAPI DismAppxsCleanup(DismSession Session, DWORD Reserved, UINT64 *CleanUpSpace, DismCallBack CallBack, LPVOID UserData);

//����������ϵͳ
HRESULT WINAPI DismCompactOs(DismSession Session, DWORD Reserved, UINT64 *CleanUpSpace, DismCallBack CallBack, LPVOID UserData);

//ʹ��NTFSӲ���Ӻϲ���ͬ�ļ�����Сϵͳ���
HRESULT WINAPI DismHardLinkMerge(DismSession Session, DWORD Reserved, UINT64 *CleanUpSpace, DismCallBack CallBack, LPVOID UserData);

//���Windows�¼���־
HRESULT WINAPI DismEventLogCleanup(DismSession Session, DWORD Reserved, UINT64 *CleanUpSpace, DismCallBack CallBack, LPVOID UserData);

//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////WIM��������//////////////////////////////////////////////////
//
//

HRESULT WINAPI DismGetMountedImages(DismMountedImage** ppMountedImages, DWORD* pCount);

//��ȡWIM��esd��VHD���ļ���Ϣ
HRESULT WINAPI DismGetImageFileInfo(LPCWSTR ImageFilePath, DismImageFileInfo** ppFileInfo);

//�޸�WIM��esd���ļ���Ϣ
HRESULT WINAPI DismSetImageFileInfo(LPCWSTR ImageFilePath, DWORD ImageIndex, DismImageInfo* pImageInfo);




#define _ExportCreate            0x00000001	//����Ŀ���ļ�
/*
����ָ��ӳ�񣬵�DesImageFile����ʱCompressTpye������
SourceImageFile����Ҫ������ӳ��·��
SourceIndex    ����Ҫ����ӳ����±�
DesImageFile   �����ڴ��Ŀ��ӳ�������������ô��ʹ��CompressTpyeָ����ѹ���ȼ��������ļ���������ļ��Ѿ����ڣ���ôCompressTpye����������
CompressTpye   ��ѹ���ȼ�
ExportFlags    ��������ǣ�����ʹ���������
*/
HRESULT WINAPI DismExportImage(LPCWSTR SourceImageFile, DWORD SourceIndex, LPCWSTR DesImageFile, DWORD ExportFlags, DismCompressTpye CompressTpye, DismCallBack CallBack, LPVOID pUserData);

//ɾ��WIM �ļ��е�ӳ��
HRESULT WINAPI DismDeleteImage(LPCWSTR FilePath, DWORD DeleteIndex);

//��ָ���±��WIM�ļ�����Ϊ�����������indxeΪ-1 ��ô���������־
HRESULT WINAPI DismSetBootImage(LPCWSTR FilePath, DWORD BootIndex);

#define _CommitAppend               0x00000001
#define _CommitVerify               0x00000002
#define _CommitNoDirAcl             0x00000010
#define _CommitNoFileAcl            0x00000020
#define _CommitNoRpFix              0x00000100

//�ύ����ӳ�����CommitFlags ӵ����������
HRESULT WINAPI DismCommitImage(LPCWSTR MountPath, DWORD CommitFlags, DismCallBack CallBack, LPVOID UserData);


#define _MountFlagReadOnly       0x00000200     //����ñ�Ǵ�����ôΪ��д���أ�����Ϊֻ������
#define _MountFlagOptimize       0x00000400
#define _MountFlagCheckIntegrity 0x00000002
//����ָ���±�ӳ������Flagsӵ����������
HRESULT WINAPI DismMountImage(LPCWSTR ImageFilePath, DWORD MountIndex, DWORD MountFlags, LPCWSTR MountPath, DismCallBack CallBack, LPVOID UserData);


#define _ApplyFlags_Verify  0x00000002   //У������
#define _ApplyFlags_WIMBoot 0x00002000   //�ͷ�WIMBoot ӳ��
#define _ApplyFlags_Compact 0x00004000   //�ͷŽ�����ӳ��
#define _ApplyFlags_WinToGo 0x10000000   //Ϊӳ������Windows To Go
/*PublicKey ʹ�ø���Key�����ڴ����*/
HRESULT WINAPI DismApplyImage(LPCWSTR ImageFilePath, DWORD ApplyIndex, DWORD ApplyFlags, LPCWSTR ApplyPath, DismCallBack CallBack, LPVOID UserData);


//ж��ָ��Ŀ¼�Ĺ���ӳ��
HRESULT WINAPI DismUnmountImage(LPCWSTR MountPath, DismCallBack CallBack, LPVOID UserData);


//���ܼ��ܵ�WIM�ļ�
HRESULT WINAPI DismDecryptWimFile(LPCWSTR FilePath, LPCWSTR PublicKey, BOOL TestKey/* ���ΪTRUE ��ô������Key�ܷ���ܴ��ļ�*/);

#define _CaptureNew                0x80000000	//�����½��ļ���ɾ����ǰ�ļ���Ĭ���������ļ��Ѿ���������ļ���
#define _CaptureSnapshot           0x40000000	//ΪĿ��������գ�ʹ�øñ�־���Բ�������ʹ�õ��ļ���һ�����ڲ�������ϵͳ��
#define _CaptureBootable           0x20000000	//��WIM�ļ�֧��,��Windows PE��ӳ����Ϊ�ܹ�����
#define _CaptureReserved           0x00000001	//��WIM�ļ�֧��
#define _CaptureVerify             0x00000002	//��WIM�ļ�֧��
#define _CaptureIndex              0x00000004	//��WIM�ļ�֧��
#define _CaptureNoApply            0x00000008	//��WIM�ļ�֧��
#define _CaptureNoDirAcl           0x00000010	//��WIM�ļ�֧��
#define _CaptureNoFileAcl          0x00000020	//��WIM�ļ�֧��
#define _CaptureShareWrite         0x00000040	//��WIM�ļ�֧��
#define _CaptureFileInfo           0x00000080	//��WIM�ļ�֧��
#define _CaptureNoRpFix            0x00000100	//��WIM�ļ�֧��
#define _CaptureApplyCiEa          0x00001000	//��WIM�ļ�֧��
//#define _CaptureWIMBoot            0x00002000	//��WIM�ļ�֧�֣����ɵ��ļ�����ʹ�� WIMBoot ���á�
/*��ĳ��·������ΪWIM��esd��VHD(X)�ļ� ��esd��VHD(X)��δ֧�֣�
ע��DismCompressTpye��������WIM�ļ���Ч ���ҽ������½��ļ��з�������*/
HRESULT WINAPI DismCaptureImage(LPCWSTR CapturePath, LPCWSTR ImageFilePath, DismCompressTpye CompressTpye, DWORD CaptureFlags, DismCallBack CallBack, LPVOID UserData, DismImageInfo* pImageInfo);

//ӳ����
HRESULT WINAPI DismSplitFile(LPCWSTR ImageFilePath, LPCWSTR SplitFilePath, UINT64 SplitSize, DismCallBack CallBack, LPVOID UserData);

//��һ��esd�ļ�ת��ΪISO�ļ�
HRESULT WINAPI DismConversionESD2ISO(LPCWSTR szWimFilePath, LPCWSTR szISOPath, DismCompressTpye CompressTpye, DismCallBack CallBack, LPVOID UserData);

//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////



//Appx֧��
HRESULT WINAPI DismGetAllUsersAppx(DismSession Session, AppxPackage** ppPackages, DWORD* pcbPackages);

HRESULT WINAPI DismRemoveAppx(DismSession Session, LPCWSTR FullName);

HRESULT WINAPI DismGetProvisionedAppxs(DismSession Session, AppxPackage** ppPackages, DWORD* pcbPackages);

HRESULT WINAPI DismRemoveProvisionedAppx(DismSession Session, LPCWSTR FullName);

enum REConfigCode
{
	//������RE
	RunREOnly = -2,

	//����RE���г�ʼ������
	InitializeRE = -1,

	//��RE�������Զ��幤�ߣ���һ�Σ�
	RunCustomToolOnce,

	//ִ��ϵͳ��ԭ����Windows.bt�е��ļ��ƶ�����ǰϵͳ��
	SystemRestore,

	//������Dism++����δʹ�ô˹��ܡ�
	Reservation1,

	//��RE�������Զ��幤�ߣ��־������
	RunCustomTool,

	MaxREConfigCode,
};

/*RE֧��
Code: ����ִ�ж���

BootID:  CodeΪ RunCustomToolOnce���� RunCustomToolʱ��Ч�������˵����������һ��32λֵ����Ҫ�������˳�ͻ�����ڲ��������˵�

FilePath��CodeΪ RunCustomToolOnce���� RunCustomToolʱ��Ч����RE����Ҫ�������ļ�·��

CallBack����ѡ���ص���������������������

UserData����ѡ����ֵ������ �ص�������UserData�����У���������ʹ��
*/
HRESULT WINAPI WinREConfig2(REConfigCode Code, DWORD BootID, LPCWSTR FilePath, DismCallBack CallBack, LPVOID UserData);


enum DismFirstBootPhase
{
	DismFirstBootPreSysPrep,
	DismFirstBootPostSysPrep,
	DismFirstBootPreOobe,
	DismFirstBootPostOobe,
};

//IBS֧�֣������״�������������
HRESULT WINAPI IbsSetFirstBootCommandLine(DismSession Session, DismFirstBootPhase Phase, LPCWSTR CommandLine);


/*AssocSupport
���ڵ���ӳ���ļ�����*/


HRESULT WINAPI DismAppAssociationsDefaultExport(DismSession Session, LPCWSTR FilePath);

HRESULT WINAPI DismAppAssociationsDefaultImport(DismSession Session, LPCWSTR FilePath);

HRESULT WINAPI DismAppAssociationsDefaultRemove(DismSession Session);

HRESULT WINAPI DismAppAssociationsExport(DismSession Session, LPCWSTR FilePath);

HRESULT WINAPI DismAppAssociationsImport(DismSession Session, LPCWSTR FilePath);

HRESULT WINAPI DismAppAssociationsRemove(DismSession Session);



#define CopyWithOptimization 0x1
#define CopyWithVSS          0x2

//��һ��ϵͳ���Ƶ���һ��Ŀ¼
HRESULT WINAPI DismCopySystem(LPCWSTR Source, LPCWSTR Target, DWORD CompactType, DWORD CopyFlags, DismCallBack CallBack, LPVOID UserData);

/*
���ڴ���Dism++�ӿ�

Session  �� Dism++�Ự���
ID       �� ��������ӿ�GUID��ֵ������ IPEImageManager��ISuStartupCollection
ppUnknown�� Dism++���صĽӿ�
*/
HRESULT WINAPI DismCreateInterface(DismSession Session, const GUID& ID, IUnknown** ppUnknown);



//PE����
MIDL_INTERFACE("745A9E3A-0DC8-4C44-8AF7-B233576C0B44")
IPEImageManager :public IUnknown
{
public:
	virtual HRESULT WINAPI get_ScratchSpace(unsigned long* pulScratchSpace) = 0;

	virtual HRESULT WINAPI put_ScratchSpace(unsigned long ulScratchSpace) = 0;

	virtual HRESULT WINAPI get_InstallRoot( BSTR* pInstallRoot) = 0;

	virtual HRESULT WINAPI put_InstallRoot(BSTR InstallRoot) = 0;
};


MIDL_INTERFACE("B3DB4480-3E38-4C39-BB44-16D47F8B6FFD")
ISuStartup :public IUnknown
{
public:
	virtual StartupType get_StartupType() = 0;
	virtual LPCWSTR get_Name() = 0;
	virtual HRESULT get_Description(LPBSTR pDescription) = 0;
	virtual HRESULT get_FilePath(LPBSTR pFilePath) = 0;
	virtual LPCWSTR get_CommandLine() = 0;
	virtual HRESULT put_State(StartupState dwState) = 0;
	virtual StartupState get_State() = 0;
};

//���ڹ���������
MIDL_INTERFACE("DCB9FFE1-8E5A-49DE-8CAE-9C9D5C53426F")
ISuStartupCollection : public IUnknown
{
public:
	virtual HRESULT WINAPI get_Count(_Out_ long* pcount) = 0;

	virtual HRESULT WINAPI get_Item(_In_ long Index, _Out_ ISuStartup** pvar) = 0;

	virtual HRESULT WINAPI get__NewEnum(_Outptr_ IUnknown** ppUnk) = 0;
};